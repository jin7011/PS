package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class 거짓말 {

	static ArrayList<Integer>[] arr;
	static ArrayList<Integer> tp = new ArrayList<Integer>();
	static Queue<Integer> que = new LinkedList<>();
	static boolean flag;
	static boolean[] visited, Q;
	static int n, m, truenum, res;

	public static int findIDX(int n) {

		for (int x = 0; x < m; x++) {
			for (int q : arr[x]) {
				if (q == n && !visited[x]) {
					visited[x] = true;
					return x;
				}
			}
		}

		return -1;
	}

	static void dfs(int trueman) {

		int party = findIDX(trueman); // 방번호 찾아서

		if (party != -1) {
			for (int q : arr[party]) {
				if (!Q[q])
					que.add(q);
			}

			dfs(trueman);
		}

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken()); // 파티수
		visited = new boolean[m];
		Q = new boolean[n + 1];

		st = new StringTokenizer(br.readLine());
		truenum = Integer.parseInt(st.nextToken());

		arr = new ArrayList[m];
		for (int x = 0; x < m; x++)
			arr[x] = new ArrayList<>();

		for (int x = 0; x < truenum; x++)
			tp.add(Integer.parseInt(st.nextToken()));

		for (int x = 0; x < m; x++) {
			st = new StringTokenizer(br.readLine());
			int people = Integer.parseInt(st.nextToken());

			for (int q = 0; q < people; q++) {
				int man = Integer.parseInt(st.nextToken());
				arr[x].add(man);
			}
		}

		if (truenum == 0) {
			System.out.println(m);
			return;
		}

		for (int q : tp) {
			if (!Q[q]) {
				Q[q] = true;
				que.add(q);
			}
		}

		while (!que.isEmpty()) {
			dfs(que.poll());
		}

		for (boolean q : visited) {
			if (q)
				res++;
		}

		System.out.println(m - res);

		// tp 따라서 파티를 확인후 거기 있는 모든 인원을 tp에 추가하고 다시 반복하면서 각각의 경우에 파티는 제외시킨다.
		// 그리하여 제외한 파티의 갯수를 총 갯수에서 제외한다.

	}

}
