package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 최단거리 {

	static class path implements Comparable<path> {
		int end, dis;

		public path(int end, int dis) {
			this.end = end;
			this.dis = dis;
		}

		@Override
		public int compareTo(path o) {
			return dis - o.dis; // 우선순위 큐에 넣었을 때 최소힙으로 구성
		}

	}

	static int v, e, s;
	static int[] D = new int[v + 1];
	static boolean[] visited = new boolean[v + 1];
	static List<path>[] arr = new ArrayList[v + 1];

	static void set() {
		arr = new ArrayList[v + 1];
		D = new int[v + 1];
		visited = new boolean[v + 1];
		Arrays.fill(D, Integer.MAX_VALUE);
		for (int x = 1; x < v + 1; x++) {
			arr[x] = new ArrayList<>();
		}

	}

	static void dijk(int start) {

		PriorityQueue<path> pq = new PriorityQueue<>();
		pq.add(new path(start,0));
		D[start] = 0;

		while (!pq.isEmpty()) {

			path p = pq.poll();
			int cur = p.end;

			if (visited[cur])
				continue;
			visited[cur] = true;

			for (path des : arr[cur]) {

				if (D[des.end] > D[cur] + des.dis) {
					D[des.end] = D[cur] + des.dis;
					pq.add(new path(des.end, D[des.end]));
				}

			}
		}

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(br.readLine());

		set();

		for (int x = 0; x < e; x++) {
			st = new StringTokenizer(br.readLine());

			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int dis = Integer.parseInt(st.nextToken());

			arr[start].add(new path(end, dis));
		}

		dijk(s);

		for (int x = 1; x < v + 1; x++) {
			if (D[x] != Integer.MAX_VALUE) {
				System.out.println(D[x]);
			} else {
				System.out.println("INF");
			}
		}

	}

}
