package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 요새푸스 {

	static int n, k;
	static ArrayList<Integer> res = new ArrayList<>();
	static Queue<Integer> que = new LinkedList<>();

	public static int pop_stack() {
		for (int x = 0; x < k - 1; x++) {
			int p = que.poll();
			que.add(p);
		}
		return que.poll();
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		for (int x = 1; x <= n; x++) {
			que.add(x);
		}

		System.out.print('<');

		while (!que.isEmpty()) {
			int ans = pop_stack();
			if (!que.isEmpty())
				System.out.print(ans + ", ");
			else
				System.out.print(ans);
		}

		System.out.print('>');

	}
}
