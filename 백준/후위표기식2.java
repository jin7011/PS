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

	static double res;
	static int n;
	static String str = "", func = "";
	static int[] arr = new int[26];
	static Stack<Double> stk = new Stack<>();

	static void cal(double num2, double num1, char c) {

		double sum = 0;

		switch (c) {
		case '+':
			sum = num1 + num2;
			stk.add(sum);
			break;

		case '-':
			sum = num1 - num2;
			stk.add(sum);
			break;

		case '/':
			sum = num1 / num2;
			stk.add(sum);
			break;

		case '*':
			sum = num1 * num2;
			stk.add(sum);
			break;

		default:
			throw new IllegalArgumentException("Unexpected value: " + c);
		}

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		str = br.readLine();

		for (int x = 0; x < n; x++) {
			arr[x] = Integer.parseInt(br.readLine());
		}

		for (int x = 0; x < str.length(); x++) {
			if (Character.isAlphabetic(str.charAt(x))) {
				stk.add((double)arr[str.charAt(x) - 65]);
			} else {
				cal(stk.pop(), stk.pop(), str.charAt(x));
			}

		}

		System.out.printf("%.2f", stk.pop());

	}

}
