package pjs20191497_mid_java2;

import java.util.Scanner;
import java.util.Random;

public class pjs20191497_java_mid02 {

	public static int result(int user, int com)
	{
		int win = 1, lose  = 2, same = 3, Error = 4;
		int Rock = 2, Scissors = 1, Paper = 3;
		if(user == Scissors)
		{
			System.out.println("유저 : 가위 ");
			if(com == Scissors)
			{
				System.out.println(" 컴퓨터 : 가위\n");
				return same;
			}
			else if(com == Rock)
			{
				System.out.println("컴퓨터 : 바위\n");
				return lose;
			}
			else
			{
				System.out.println("컴퓨터 : 보");
				return win;
			}
		}
		else if(user == Rock)
		{
			System.out.println("유저 : 바위 ");
			if(com == Scissors)
			{
				System.out.println(" 컴퓨터 : 가위\n");
				return win;
			}
			else if(com == Rock)
			{
				System.out.println("컴퓨터 : 바위\n");
				return same;
			}
			else
			{
				System.out.println("컴퓨터 : 보");
				return lose;
			}
		}
		else if(user == Paper)
		{
			System.out.println("유저 : 보 ");
				if(com == Scissors)
				{
					System.out.println(" 컴퓨터 : 가위\n");
					return lose;
				}
				else if(com == Rock)
				{
					System.out.println("컴퓨터 : 바위\n");
					return win;
				}
				else
				{
					System.out.println("컴퓨터 : 보");
					return same;
				}
		}
		else
		{
			return Error;
		}
	}
	
	public static void GoGame()
	{
		int win =1, Lose  = 2, same = 3, Error =4;
		int life = 1;
		int stackwin = 0;
		while(life==1)
		{
			System.out.println("=============\n");
			System.out.println("1.가위\n");
			System.out.println("2.바위\n");
			System.out.println("3.보\n");
			System.out.printf("현재 연승 기록 : %d",stackwin);
			Scanner sc = new Scanner(System.in);
			int user = sc.nextInt();
			int com = (int)(Math.random()*3)+1;
			int Result = result(user,com);
			if(Result == win )
			{
				System.out.println("이겼습니다");
				stackwin +=1;
			}
			else if(Result == same)
			{
				System.out.println("비겼습니다");
			}
			else if(Result == Lose)
			{
				System.out.println("졌습니다.");
				break;
			}
			else
			{
				System.out.println("다시 적어주세요");
			}
		}
	}
	public static int record()
	{	
		Scanner sc= new Scanner(System.in);
		System.out.println("======High score=====\n");
		System.out.println("기록을 입력하세요 : ");
		int score = sc.nextInt();
		
		return score;
	}
	public static String UserName()
	{	
		
		Scanner sc= new Scanner(System.in);
		System.out.println("======게임 시작하기전=====\n");
		System.out.println("이름을 입력하세요 : ");
		String Name;
		Name = sc.nextLine();
		return Name;
	}

	public static  void GameMenu()
	{
		int Currentrecord=0;
		int Exit = 1;
		int currentwin = 0;
		int highestwin = 0;
		String RecordHolder = "없음";
		String Name = "없음";
		while(Exit != 0)
		{
			
			Scanner menu = new Scanner(System.in); 
			System.out.println("====가위바위보게임====\n");
			System.out.println("1.게임 시작\n");
			System.out.println("2.게임 종료\n");
			System.out.printf("이용자 :%s 최고기록 : %d승",RecordHolder,highestwin);
			int Menu = menu.nextInt();
			switch(Menu)
			{
				case 1: 
					Name = UserName();
					GoGame();
					Currentrecord = record();
					if(highestwin < Currentrecord)
					{
						highestwin = Currentrecord;
						RecordHolder = Name;
					}
					break;
				case 2:
				case 3:
					Exit = 0;
					break;
					
					
			
			}
		}
	}
	public static void main(String[] args) {
		GameMenu();

	}

}
