package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class 크게만들기 { //문제 환경이 구림 메모리도 그렇고 순서를 빠꾸면 안된다는 조건도 안적혀있음

	static int N, K;

	static Stack<Integer> func(String num) {
		
		int cnt = 0;
		Stack<Integer> stk = new Stack<>();
		
		for(int x=0; x<num.length(); x++) {
			
			int next = num.charAt(x) - '0';
			
			while(!stk.isEmpty() && stk.peek() < next && cnt<K) {
				stk.pop();
				cnt++;
			}
			
			stk.add(next);
		}
		
		return stk;

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		String num;
		
		num = br.readLine();
		Stack<Integer> stk = func(num);
		
		StringBuffer sb = new StringBuffer();
		
		for(int x=0; x<stk.size(); x++) {
			sb.append(stk.get(x));
		}
			
		System.out.println(sb);
	}
}
