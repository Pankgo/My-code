package pjs20191497_mid_java01;

import java.util.Scanner;

public class pjs20191497_java_mid01 {

	public static void main(String[] args) {
		int T = 1;
		while(T !=0)
		 {
			System.out.println("====����������====\n");
			System.out.println("1.����\n");
			System.out.println("2.����\n");
			System.out.println("3.��\n");
			System.out.println("4.����\n");
			Scanner sc = new Scanner(System.in);
			int user = sc.nextInt();
			int com = (int)(Math.random()*3)+1;
			if(user<=3&&user>com)
			{
				System.out.println("�̰���ϴ�.");
			}
			else if(user<=3&&user==com)
			{
				System.out.println("�����ϴ�.");
			}
			else if(user<=3&&user<com)
			{
				System.out.println("�����ϴ�.");
			}
			else if(user == 4)
			{
				T = 0;
			}
			else
			{
				System.out.println("�߸��Է��߽��ϴ�.");
			}
		 }

	}

}
