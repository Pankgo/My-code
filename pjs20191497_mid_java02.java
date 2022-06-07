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
			System.out.println("���� : ���� ");
			if(com == Scissors)
			{
				System.out.println(" ��ǻ�� : ����\n");
				return same;
			}
			else if(com == Rock)
			{
				System.out.println("��ǻ�� : ����\n");
				return lose;
			}
			else
			{
				System.out.println("��ǻ�� : ��");
				return win;
			}
		}
		else if(user == Rock)
		{
			System.out.println("���� : ���� ");
			if(com == Scissors)
			{
				System.out.println(" ��ǻ�� : ����\n");
				return win;
			}
			else if(com == Rock)
			{
				System.out.println("��ǻ�� : ����\n");
				return same;
			}
			else
			{
				System.out.println("��ǻ�� : ��");
				return lose;
			}
		}
		else if(user == Paper)
		{
			System.out.println("���� : �� ");
				if(com == Scissors)
				{
					System.out.println(" ��ǻ�� : ����\n");
					return lose;
				}
				else if(com == Rock)
				{
					System.out.println("��ǻ�� : ����\n");
					return win;
				}
				else
				{
					System.out.println("��ǻ�� : ��");
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
			System.out.println("1.����\n");
			System.out.println("2.����\n");
			System.out.println("3.��\n");
			System.out.printf("���� ���� ��� : %d",stackwin);
			Scanner sc = new Scanner(System.in);
			int user = sc.nextInt();
			int com = (int)(Math.random()*3)+1;
			int Result = result(user,com);
			if(Result == win )
			{
				System.out.println("�̰���ϴ�");
				stackwin +=1;
			}
			else if(Result == same)
			{
				System.out.println("�����ϴ�");
			}
			else if(Result == Lose)
			{
				System.out.println("�����ϴ�.");
				break;
			}
			else
			{
				System.out.println("�ٽ� �����ּ���");
			}
		}
	}
	public static int record()
	{	
		Scanner sc= new Scanner(System.in);
		System.out.println("======High score=====\n");
		System.out.println("����� �Է��ϼ��� : ");
		int score = sc.nextInt();
		
		return score;
	}
	public static String UserName()
	{	
		
		Scanner sc= new Scanner(System.in);
		System.out.println("======���� �����ϱ���=====\n");
		System.out.println("�̸��� �Է��ϼ��� : ");
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
		String RecordHolder = "����";
		String Name = "����";
		while(Exit != 0)
		{
			
			Scanner menu = new Scanner(System.in); 
			System.out.println("====��������������====\n");
			System.out.println("1.���� ����\n");
			System.out.println("2.���� ����\n");
			System.out.printf("�̿��� :%s �ְ��� : %d��",RecordHolder,highestwin);
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
