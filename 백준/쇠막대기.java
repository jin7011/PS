package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 쇠막대기 {

	static String str;
	static Stack<Character> stk = new Stack<Character>();
	static int sum = 0;

	static public boolean isRazor(int idx) {

		char next = str.charAt(idx);

		if (idx != str.length() - 1) {
			char nextnext = str.charAt(idx + 1);

			if (next == '(' && nextnext == ')') {
				stk.add('*');
				return true;
			}
		}

		return false;

	}

	static public void cal() {

		int cnt = 0;

		for (int x = stk.size()-1; x >= 0; x--) {

			int next = stk.get(x);

			if (next == '(') {
				stk.remove(x);
				sum += cnt + 1;
				break;

			} else if (next == '*') {
				cnt++;
			}
		}


	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();
//
//		for (int x = 0; x < str.length(); x++) {
//
//			char next = str.charAt(x);
//
//			if (isRazor(x)) {
//				x++;
//				continue;
//			}
//
//			else if (next == ')') {
//				cal();
//			}
//
//			else if (next == '(') {
//				stk.add(next);
//			}
//
//		}
//
//		System.out.println(sum);
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
//			if(next == '(')
//				s.add(x);
//			else if(s.pop() == x-1)
//				sum += s.size();
//			else
//				sum++;
//			
			
		}
		System.out.println(sum);
	}

}
