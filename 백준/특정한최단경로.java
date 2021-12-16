package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 특정한최단경로 {

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

	static void reset() {
		Arrays.fill(D, Integer.MAX_VALUE);
		Arrays.fill(visited, false);
	}

	static int dijk(int start, int v) {

		reset();
		PriorityQueue<path> pq = new PriorityQueue<>();
		pq.add(new path(start, 0));
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

		return D[v];

	}

	static void show() {

		for (int x = 1; x < v + 1; x++) {
			if (D[x] != Integer.MAX_VALUE) {
				System.out.println(D[x]);
			} else {
				System.out.println("INF");
			}
		}
	}

	static boolean ch(int a, int b, int c) {
		return a != Integer.MAX_VALUE && b != Integer.MAX_VALUE && c != Integer.MAX_VALUE;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());

		set();

		for (int x = 0; x < e; x++) {
			st = new StringTokenizer(br.readLine());

			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int dis = Integer.parseInt(st.nextToken());

			arr[start].add(new path(end, dis));
			arr[end].add(new path(start, dis));
		}

		st = new StringTokenizer(br.readLine());
		int v1 = Integer.parseInt(st.nextToken());
		int v2 = Integer.parseInt(st.nextToken());

//		int temp1 = dijk(1, v1); // 시작점 ~ 2
//		int temp2 = dijk(1, v2); // 시작점 ~ 3
//		int res = 0;
//
//		if (temp1 > temp2) { // 시작점 ~ 3이 더 짧으면
//			res = temp2;
//			res += dijk(v2, v1); // 3~2
//			res += dijk(v1, v); //2~끝점
//		} else {
//			res = temp1;
//			res += dijk(v1, v2);
//			res += dijk(v2, v);
//		}
//		
		int res = 0;
		int[] tempt = new int[2];
		if (ch(dijk(1, v1), dijk(v1, v2), dijk(v2, v)))
			tempt[0] = dijk(1, v1) + dijk(v1, v2) + dijk(v2, v);
		if (ch(dijk(1, v2), dijk(v2, v1), dijk(v1, v)))
			tempt[1] = dijk(1, v2) + dijk(v2, v1) + dijk(v1, v);
		
		// tempt[2] += dijk(1,v)+dijk(v,v1)+dijk(v1,v2);
		// tempt[3] += dijk(1,v)+dijk(v,v2)+dijk(v2,v1);
		// tempt[4] += dijk(1,v1)+dijk(v1,v)+dijk(v,v2);
		// tempt[5] += dijk(1,v2)+dijk(v2,v)+dijk(v,v1); 
		
		res = Math.min(tempt[0], tempt[1]);

		System.out.println(res);
	}
}