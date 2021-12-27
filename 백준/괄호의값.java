package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 괄호의값 {

	static int n, ans = 0;
	static String str = "";
	static boolean[] visited = new boolean[31];
	static Stack<Character> stk = new Stack<>();

	// (()[[]])([])
	// 바로 나오면 일단 숫자
	// ((
	static int dfs(int idx, int val) {

		char c = str.charAt(idx);
		char goal;
		int sum = 0;
		int val2 = 0;

		visited[idx] = true;
		stk.add(c);

		if (c == '(')
			goal = ')';
		else
			goal = ']';

		for (int x = idx + 1; x < str.length(); x++) {

			char next = str.charAt(x);

			if (visited[x])
				continue;

			if (next == '(') {
				val2 = 2;
//				sum += dfs(x, val2);  다음 괄호의 모양에 따라 dfs를 사용하면 올바르지 못한 괄호같은 반례를 쳐낼 수가 없다 (올바르지 못한 괄호를 지나쳐버려서)
			} else if (next == '[') {
				val2 = 3;
//				sum += dfs(x, val2);
			}

			if (next == goal) { // ( [
				stk.pop();
				visited[x] = true;
				if (sum == 0) {
					return val;
				} else {
					return val * sum;
				}
			} 
			else { //else문으로 올바르지 못한 괄호까지 처리할 수 있게 해주어야 stack처리가 되어서 반례에 0이 나온다
				sum += dfs(x, val2);
			}
		}
		return sum * val;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();

		for (int x = 0; x < str.length(); x++) {
			if (!visited[x]) {
				int v = 0;
				if (str.charAt(x) == '(')
					v = 2;
				else if (str.charAt(x) == '[')
					v = 3;
				
				ans += dfs(x, v);
			}
		}

		if (stk.size() != 0)
			System.out.println(0);
		else
			System.out.println(ans);

	}
}
