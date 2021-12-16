package 프로그래머스;

import java.util.Arrays;

public class 가장큰수 {

	static boolean[] visited = new boolean[100000];
	static int max = 0;
	static String[] str;

	static int cal(String[] str) {

		String q = "";
		for (String s : str) {
			q += s;
		}
		return Integer.parseInt(q);
	}

	static void func(int[] arr, int cnt, int len) {

		if (cnt == len) 
			max = Math.max(max, cal(str));	

		for (int x = 0; x < len; x++) {

			if (!visited[x]) {
				visited[x] = true;
				str[cnt] = String.valueOf(arr[x]);
				func(arr, cnt + 1, len);
				visited[x] = false;
			}
		}
	}

	public static void main(String[] args) {

		int[] numbers = { 3, 30, 34, 5, 9 };
		str = new String[numbers.length];
		String answer = "";
		func(numbers,0,numbers.length);
		
		answer = String.valueOf(max);

		System.out.println(answer);

	}

}
