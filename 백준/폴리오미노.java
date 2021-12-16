package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 폴리오미노 {

	static Stack<Character> stk = new Stack<>();
	static char ch;
	static String str, res = "";

	static void print(int cnt) {

		if (cnt == 3)
			return;

		while (cnt >= 2) {

			if (cnt >= 4) {
				for (int x = 0; x < 4; x++) {
					res += "A";
					cnt--;
				}
			}

			else if (cnt == 2) {
				for (int x = 0; x < 2; x++) {
					res += "B";
					cnt--;
				}
			}

			else if (cnt == 3)
				return;

		}

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();

		int cnt = 0;

		for (int x = 0; x < str.length(); x++) {
			char next = str.charAt(x);
			cnt++; // x 갯수

			if (next == '.') {
				cnt--;
				print(cnt);
				cnt = 0;
				res += ".";
			}

		}

		print(cnt);

		if (str.length() != res.length())
			System.out.println(-1);
		else
			System.out.println(res);
	}

}
