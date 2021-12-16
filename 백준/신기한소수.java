package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 신기한소수 {

	static String res, a = "";
	static int n;
	static int[] first = { 2, 3, 5, 7 };
	static boolean[] visited = new boolean[10];

	static public boolean isprime(int n) {

		for (int x = 2; x <= Math.sqrt(n); x++) {
			if (n % x == 0)
				return false;
		}

		return true;
	}

	public static void dfs(String str, int add, int cnt) {
		String temp = str + add;

		if (isprime(Integer.parseInt(temp))) {

			if (cnt == n)
				System.out.println(temp);
			else {

				for (int x = 0; x <= 9; x++)
					dfs(temp, x, cnt + 1);

			}
		} else
			return;

	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());

		if (n == 1) {
			for (int x : first)
				System.out.println(x);
		} else
			for (int x : first) {
				dfs(a, x, 1);
			}

	}

}
