package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.StringTokenizer;

public class n과m2 {

	static int m, n;
	static Integer[] ch = new Integer[8];
	static boolean[] visited = new boolean[8];

	static void dfs(int cnt) {

		if (cnt == m) {
			// 출력
			String str = "";
			for (int x = 0; x < ch.length; x++) {
				if (ch[x] != null)
					str += ch[x] + " ";
			}
			System.out.println(str);
			return;
		}

		for (int x = 1; x <= n; x++) {

			if (!visited[x]) {
				visited[x] = true;

//				ch[cnt] = x;
//				dfs(cnt + 1);
				if (cnt >= 1 && ch[cnt - 1] <= x) {
					ch[cnt] = x;
					dfs(cnt + 1);
				} else if (cnt == 0) {
					ch[cnt] = x;
					dfs(cnt + 1);
				}

				visited[x] = false;
			}
		}
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		dfs(0);
	}

}
