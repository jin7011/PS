package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 요새푸스 {

	static int n, k;
	static Queue<Integer> que = new
		LinkedList<>();
	static StringBuilder str = new StringBuilder();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		for (int x = 1; x <= n; x++) {
			que.add(x);
		}

		int cnt = 0;

		while (que.size() != 1) {

			cnt++;
			
			if(cnt == k) {
				str.append(que.poll()+", ");
				cnt = 0;
			}else {
				que.add(que.poll());
			}
			

		}
		
		str.append(que.poll());
		System.out.print("<");
		
		System.out.print(str);
		
		System.out.print(">");
	}
}
