package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 쇠막대기 {

	static String str;
	static Stack<Character> stk = new Stack<Character>();
	static int sum = 0;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();

		Stack<Integer> s = new Stack<>();
		for (int x = 0; x < str.length(); x++) {
			char next = str.charAt(x);
			
			if(next == ')' && s.peek() == x-1) {
				s.pop();
				sum+=s.size();
			}
			else if(next == '(')
				s.add(x);
			else if(next == ')') {
				s.pop();
				sum ++;
			}

		}
		System.out.println(sum);
	}

}
