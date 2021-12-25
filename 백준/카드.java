package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class 카드 {
	
	static int n;
	static Queue<Integer> que = new LinkedList<>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		for(int x=1; x<=n; x++)
			que.add(x);
		
		while(que.size() != 1) {
			que.poll();
			int p = que.poll();
			que.add(p);
		}
		System.out.println(que.peek());

	}

}
