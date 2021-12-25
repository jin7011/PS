package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class 후위표기식2 {

	static int n;
	static int[] arr = new int[26];
	static String str;
	static Stack<Double> stk = new Stack<>();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		str = br.readLine();
		
		for(int x=0; x<n; x++) {
			arr[x] = Integer.parseInt(br.readLine());
		}
		
		for(int x=0; x<str.length();x++) {
			char c = str.charAt(x);
			
			if(Character.isAlphabetic(c)) {
				stk.add((double)arr[c-65]);
			}else {
				double x2 = stk.pop();
				double x1 = stk.pop();
				
				if(c == '+')
					stk.add(x1+x2);
				else if(c == '-')
					stk.add(x1-x2);
				else if(c == '*')
					stk.add(x1*x2);
				else
					stk.add(x1/x2);
			}
		}
		System.out.printf("%.2f",stk.pop());
	}

}
