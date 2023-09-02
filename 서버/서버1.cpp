
//#include<Windows.h>
#define _WINSOCKAPI_
#include <windows.h>
#include <stdio.h>
#include <winsock2.h>
#include <vector>

#pragma comment(lib, "Ws2_32.lib")

#define MAX_BUFFER        1024
#define SERVER_PORT        3500

struct SOCKETINFO
{
    WSAOVERLAPPED overlapped;
    WSABUF dataBuffer;
    SOCKET socket;
    char messageBuffer[MAX_BUFFER];
    int receiveBytes;
    int sendBytes;
};

DWORD WINAPI makeThread(LPVOID hIOCP);

int main(int argc, char* argv[])
{
    // Winsock Start - windock.dll 로드
    WSADATA WSAData;
    if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
    {
        printf("Error - Can not load 'winsock.dll' file\n");
        return 1;
    }

    // 1. 소켓생성  
    SOCKET listenSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (listenSocket == INVALID_SOCKET)
    {
        printf("Error - Invalid socket\n");
        return 1;
    }

    SOCKADDR_IN serverAddr;

    // 서버정보 객체설정
    memset(&serverAddr, 0, sizeof(SOCKADDR_IN));
    serverAddr.sin_family = PF_INET;
    serverAddr.sin_port = htons(SERVER_PORT); 
    serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    
    // 2. 소켓설정
    if (bind(listenSocket, (struct sockaddr*)&serverAddr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
        printf("Error - Fail bind\n");
        // 6. 소켓종료
        closesocket(listenSocket);
        // Winsock End
        WSACleanup();
        return 1;
    }

    // 3. 수신대기열생성
    if (listen(listenSocket, 5) == SOCKET_ERROR)
    {
        printf("Error - Fail listen\n");
        // 6. 소켓종료
        closesocket(listenSocket);
        // Winsock End
        WSACleanup();
        return 1;
    }

    // 완료결과를 처리하는 객체(CP : Completion Port) 생성
    HANDLE hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);

    // 워커스레드 생성
    // - CPU * 2개
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    int threadCount = systemInfo.dwNumberOfProcessors * 2;
    unsigned long threadId;
    // - thread Handler 선언
    HANDLE* hThread = (HANDLE*)malloc(threadCount * sizeof(HANDLE));
    // - thread 생성
    for (int i = 0; i < threadCount; i++)
    {
        hThread[i] = CreateThread(NULL, 0, makeThread, &hIOCP, 0, &threadId);
    }

    SOCKADDR_IN clientAddr;
    int addrLen = sizeof(SOCKADDR_IN);
    memset(&clientAddr, 0, addrLen);
    int start = 0;
   
    SOCKET clientSocket;
    std::vector<SOCKETINFO> socketInfo;
    SOCKETINFO* eventSocket;
    DWORD receiveBytes;
    DWORD flags;


    while (1)
    {
        clientSocket = accept(listenSocket, (struct sockaddr*)&clientAddr, &addrLen); // 다른 클라이언트가 생성될때까지 대기
        if (clientSocket == INVALID_SOCKET)
        {
            printf("Error - Accept Failure\n");
            return 1;
        }

        eventSocket = (struct SOCKETINFO*)malloc(sizeof(struct SOCKETINFO));
        memset((void*)eventSocket, 0x00, sizeof(struct SOCKETINFO));
        eventSocket->socket = clientSocket;
        eventSocket->receiveBytes = 0;
        eventSocket->sendBytes = 0;
        eventSocket->dataBuffer.len = MAX_BUFFER;
        eventSocket->dataBuffer.buf = eventSocket->messageBuffer;
        flags = 0;

        hIOCP = CreateIoCompletionPort((HANDLE)clientSocket, hIOCP, (DWORD)eventSocket, 0);

        // 중첩 소캣을 지정하고 완료시 실행될 함수를 넘겨준다.
        socketInfo.push_back(*eventSocket);

        for (auto socket : socketInfo)
        {
            if (WSARecv(socket.socket, &socket.dataBuffer, 1, &receiveBytes, &flags, &(socket.overlapped), NULL))
            {
                if (WSAGetLastError() != WSA_IO_PENDING)
                {
                    printf("Error - IO pending Failure\n");
                    return 1;
                }
            }
        }
    }

    // 6-2. 리슨 소켓종료
    closesocket(listenSocket);

    // Winsock End
    WSACleanup();

    return 0;
}

DWORD WINAPI makeThread(LPVOID hIOCP)
{
    HANDLE threadHandler = *((HANDLE*)hIOCP);
    DWORD receiveBytes;
    DWORD sendBytes;
    unsigned long long completionKey;
    DWORD flags;
    struct SOCKETINFO* eventSocket;
    unsigned long long keyset;

    while (1)
    {
        // 입출력 완료 대기
        if (GetQueuedCompletionStatus(threadHandler, &receiveBytes, &completionKey, (LPOVERLAPPED*)&eventSocket, INFINITE) == 0)
        {
            printf("Error - GetQueuedCompletionStatus Failure\n");
            closesocket(eventSocket->socket);
            free(eventSocket);
            return 1;
        }
        

        struct SOCKETINFO *socketInfo = (struct SOCKETINFO*)completionKey;
        eventSocket->dataBuffer.len = receiveBytes;

        if (receiveBytes == 0)
        {
            closesocket(eventSocket->socket);
            free(eventSocket);
            continue;
        }
        else
        {
            printf("TRACE - Receive message : %s (%d bytes)\n", eventSocket->dataBuffer.buf, eventSocket->dataBuffer.len);

            
            if (WSASend(eventSocket->socket, &(eventSocket->dataBuffer), 1, &sendBytes, 0, NULL, NULL) == SOCKET_ERROR)
            {
                if (WSAGetLastError() != WSA_IO_PENDING)
                {
                    printf("Error - Fail WSASend(error_code : %d)\n", WSAGetLastError());
                }
            }

            printf("TRACE - Send message : %s (%d bytes)\n", eventSocket->dataBuffer.buf, eventSocket->dataBuffer.len);

            memset(eventSocket->messageBuffer, 0x00, MAX_BUFFER);
            eventSocket->receiveBytes = 0;
            eventSocket->sendBytes = 0;
            eventSocket->dataBuffer.len = MAX_BUFFER;
            eventSocket->dataBuffer.buf = eventSocket->messageBuffer;
            flags = 0;

            if (WSARecv(eventSocket->socket, &(eventSocket->dataBuffer), 1, &receiveBytes, &flags, &eventSocket->overlapped, NULL) == SOCKET_ERROR)
            {
                if (WSAGetLastError() != WSA_IO_PENDING)
                {
                    printf("Error - Fail WSARecv(error_code : %d)\n", WSAGetLastError());
                }
            }
        }
    }
}

