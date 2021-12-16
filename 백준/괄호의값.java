package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 괄호의값 {

	static char[] ch = new char[31];
	static boolean[] visited = new boolean[31];
	static String str;
	static int res = 0;
	static Stack<Character> stk = new Stack<>();

	static public int dfs(int idx, int val, char ch) {

		visited[idx] = true;
		stk.add(ch);

		int sum = 0;
		char goal;
		int val2 = 0;

		if (ch == '(')
			goal = ')';
		else
			goal = ']'; // ([]())

		for (int x = idx + 1; x < str.length(); x++) {
			if (visited[x])
				continue;

			char next = str.charAt(x);

			if (next == '(')
				val2 = 2;
			else if (next == '[')
				val2 = 3;

			if (next != goal) {
				sum += dfs(x, val2, next);
			} else {
				visited[x] = true;
				stk.pop();
				if (sum == 0)
					return val;
				else
					return val * sum;

			}
		}

		return sum * val;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();

		for (int x = 0; x < str.length(); x++) {

			if (!visited[x]) {
				int val = 0;
				if (str.charAt(x) == '(')
					val = 2;
				else if (str.charAt(x) == '[')
					val = 3;

				res += dfs(x, val, str.charAt(x));
			}
		}

		if (stk.size() == 0)
			System.out.println(res);
		else
			System.out.println(0);

	}

}
