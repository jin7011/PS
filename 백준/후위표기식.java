package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 후위표기식 {

	static String str = "";
	static String res = "";
	static Stack<Character> stk = new Stack<Character>();

	static int priority(char c) {
		if (c == '(')
			return 0;
		if (c == '+' || c == '-')
			return 1;
		else if (c == '*' || c == '/')
			return 2;

		return -1;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();

		for (int x = 0; x < str.length(); x++) {

			char next = str.charAt(x);

			if (Character.isAlphabetic(str.charAt(x))) { // ABCD
				res += next;
			} else if (next == '(')
				stk.push(next); // ( 는 그대로 넣어줌

			else if (next == ')') { // ( 만날때까지 출력
				while (!stk.isEmpty()) {
					if (stk.peek() == '(') {
						stk.pop();
						break;
					}
					res += stk.pop();
				}
			} else {
				while (!stk.isEmpty() && priority(next) <= priority(stk.peek())) {
					res += stk.pop();
				}
				stk.push(next);
			}
		}

		while (!stk.isEmpty())
			res += stk.pop();

		System.out.println(res);

	}
}
