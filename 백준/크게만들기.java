package ����;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class ũ�Ը���� { //���� ȯ���� ���� �޸𸮵� �׷��� ������ ���ٸ� �ȵȴٴ� ���ǵ� ����������

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
