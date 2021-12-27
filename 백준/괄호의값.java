package ����;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class ��ȣ�ǰ� {

	static int n, ans = 0;
	static String str = "";
	static boolean[] visited = new boolean[31];
	static Stack<Character> stk = new Stack<>();

	// (()[[]])([])
	// �ٷ� ������ �ϴ� ����
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
//				sum += dfs(x, val2);  ���� ��ȣ�� ��翡 ���� dfs�� ����ϸ� �ùٸ��� ���� ��ȣ���� �ݷʸ� �ĳ� ���� ���� (�ùٸ��� ���� ��ȣ�� �����Ĺ�����)
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
			else { //else������ �ùٸ��� ���� ��ȣ���� ó���� �� �ְ� ���־�� stackó���� �Ǿ �ݷʿ� 0�� ���´�
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
