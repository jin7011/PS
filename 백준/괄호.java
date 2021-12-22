package น้มุ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class ฐýศฃ {

	static int n;

	public static String func1(String str) {

		Stack<Character> stk = new Stack<>();

		for (int x = 0; x < str.length(); x++) {
			char c = str.charAt(x);

			if (c == '(')
				stk.push(c);
			else if(!stk.isEmpty() && c== ')')
				stk.pop();
			else
				return "NO";
		}

		if (!stk.isEmpty())
			return "NO";
		else
			return "YES";
	}
	

	public static void main(String[] args) throws IOException {

		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(bf.readLine());
		
		for(int x=0; x<n; x++) {
			String str = bf.readLine();
			System.out.println(func1(str));
		}

	}
}
