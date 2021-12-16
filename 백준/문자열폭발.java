package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;


public class 문자열폭발 {

	static boolean find(Stack<Character> stk,String boom) {
		
		for(int x = 0; x<boom.length(); x++) {
			if(stk.get(stk.size()+x - (boom.length())) != boom.charAt(x)) return false;
		}
		
		return true;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		String boom = br.readLine();
		Stack<Character> stk = new Stack<>();

		for(int x =0; x<str.length(); x++) {
			stk.push(str.charAt(x));
			if(stk.size() >= boom.length()) {
				if(find(stk,boom)) {
					for(int q=0; q<boom.length(); q++)
					stk.pop();
				}
			}
		}

		if (stk.isEmpty())
			System.out.println("FRULA");
		else {
			str = "";
			for(Character c: stk)
				str += c;
			System.out.println(str);
		}

	}

}
