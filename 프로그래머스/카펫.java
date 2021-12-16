package 프로그래머스;

import java.util.ArrayList;

public class 카펫 {

	// {(x-3)+1} * {(y-3)+1} = 노란색
	// 주어진것: 갈색 노란색

	static class pair {
		int a, b;

		pair(int a, int b) {
			this.a = a;
			this.b = b;

		}
	}

	static ArrayList<pair> func(int n) {

		ArrayList<pair> arr = new ArrayList<pair>();

		for (int x = 3; x <= n; x++) { // x 는 세로
			if (n % x == 0)
				arr.add(new pair(n / x, x));
		}
		return arr;
	}
	

	static int[] func2(int n,int yellow) {
		
		for (int x = 3; x <= n; x++) { // x 는 세로
			if (n % x == 0 && (n/x-2)*(x-2) == yellow) {
				return new int[] {n/x,x};
			}
		}
		return null;
	}

//	static ArrayList<pair> cal(ArrayList<pair> arr, int yellow) {
//		for (pair p : arr) {
//			if (((p.a - 3) + 1) * ((p.b - 3) + 1) == yellow) {
//				int a = p.a;
//				int b = p.b;
//				arr.clear();
//				arr.add(new pair(a, b));
//				return arr;
//			}
//		}
//		return null;
//	}

	public static void main(String[] args) {
		int a = 16;
		int b = 8;
		
		ArrayList<pair> temp = new ArrayList<pair>();
		
		//temp = cal(func(a+b),b);
		
		int[] answer = func2(a+b,b);
		
		for(int f : answer) {
			System.out.println(f);
		}
		
	}

}
