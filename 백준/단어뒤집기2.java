package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 단어뒤집기2 {

	static String str, res = "";
	static Stack<Character> stk = new Stack<>();
	static int idx;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();

		for (int x = 0; x < str.length(); x++) {

			char next = str.charAt(x);

			if (next == ' ') {
				write();
				res+=" ";
				continue;
			}
			if (next == '<') {
				write();
				
				for(int q = x; q<str.length(); q++) {
					
					char in_next = str.charAt(q);
					res+=in_next;
					
					if(in_next == '>') {
						x = q;
						break;
					}
				}
				
				continue;
				
			}

			stk.add(next);
		}
		
		write();
		System.out.println(res);

	}

	private static void write() {
		
		while (!stk.isEmpty()) {
			res += stk.pop();
		}
		
	}
	
}
