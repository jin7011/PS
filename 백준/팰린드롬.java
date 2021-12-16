package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 팰린드롬 {

	static String str;
	static boolean flag = false;
	static int[] arr;
	static String res = "";
	static int odd = -1;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();
		arr = new int[26];

		for (int x = 0; x < str.length(); x++) {
			int pos = (int) str.charAt(x) - 65;
			arr[pos]++;
		}

		for (int x = 0; x < 26; x++) {
			if (arr[x] != 0) {
				for (int q = 0; q < arr[x] / 2; q++) {
					res += (char) (x + 65);
				}
				if (arr[x] % 2 != 0) {
					if (flag) {
						System.out.println("I'm Sorry Hansoo");
						return;
					}
					flag = true;
					odd = x;
				}
			}
		}

		if(odd!=-1)
		res += (char)(odd + 65);

		for (int x = 25; x >= 0; x--) {
			if (arr[x] != 0)
				for (int q = 0; q < arr[x] / 2; q++) {
					res += (char) (x + 65);
				}
		}

		System.out.println(res);
	}

}
