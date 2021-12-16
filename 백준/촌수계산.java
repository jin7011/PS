package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 촌수계산 {

	static int total, start, end, nodeCnt, res = -1;
	static ArrayList<Integer>[] arr;
	static boolean[] visited;

	static public void dfs(int cnt, int go, int des) {

		if (go == des)
			res = cnt;

		visited[go] = true;

		for (int x = 0; x < arr[go].size(); x++) {
			if (!visited[arr[go].get(x)]) {
				dfs(cnt + 1, arr[go].get(x), des);
			}
		}

		visited[go] = false;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		total = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new ArrayList[total];
		visited = new boolean[total];

		start = Integer.parseInt(st.nextToken());
		end = Integer.parseInt(st.nextToken());
		start--;
		end--;
		st = new StringTokenizer(br.readLine());
		nodeCnt = Integer.parseInt(st.nextToken());

		for (int x = 0; x < total; x++) {
			arr[x] = new ArrayList<>();
		}

		for (int x = 0; x < nodeCnt; x++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			arr[a-1].add(b-1);
			arr[b-1].add(a-1);

		}

		for (int x = 0; x < total; x++) {
			dfs(0, start, end);
		}

		System.out.println(res);

	}
}
