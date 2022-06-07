package pjs20191497_mid_java01;

import java.util.Scanner;

public class pjs20191497_java_mid01 {

	public static void main(String[] args) {
		int T = 1;
		while(T !=0)
		 {
			System.out.println("====가위바위보====\n");
			System.out.println("1.가위\n");
			System.out.println("2.바위\n");
			System.out.println("3.보\n");
			System.out.println("4.종료\n");
			Scanner sc = new Scanner(System.in);
			int user = sc.nextInt();
			int com = (int)(Math.random()*3)+1;
			if(user<=3&&user>com)
			{
				System.out.println("이겼습니다.");
			}
			else if(user<=3&&user==com)
			{
				System.out.println("비겼습니다.");
			}
			else if(user<=3&&user<com)
			{
				System.out.println("졌습니다.");
			}
			else if(user == 4)
			{
				T = 0;
			}
			else
			{
				System.out.println("잘못입력했습니다.");
			}
		 }

	}

}
