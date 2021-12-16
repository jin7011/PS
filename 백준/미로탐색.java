package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 미로탐색 {

	static int[][] map = new int[100][100];
	static int[][] visited = new int[100][100];
	static int n, m;
	static Queue<pair> que = new LinkedList<pair>();
	static int[][] go = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

	static public class pair {

		int y, x;

		pair(int y, int x) {
			this.y = y;
			this.x = x;
		}

	}

	static boolean isrange(int y, int x) {
		return y >= 0 && y < n && x >= 0 && x < m;
	}

	static void bfs(int y, int x) {

		que.add(new pair(y, x));
		visited[y][x] = 1;

		while (!que.isEmpty()) {

			int tempy = que.peek().y;
			int tempx = que.poll().x;

			for (int q = 0; q < 4; q++) {

				int dy = tempy + go[q][0];
				int dx = tempx + go[q][1];

				if (isrange(dy, dx) && map[dy][dx] == 1 && visited[dy][dx] == 0) {

					if (dy == n - 1 && dx == m - 1) {
						System.out.println(visited[tempy][tempx] + 1);
						return;
					} else {
						que.add(new pair(dy, dx));
						visited[dy][dx] = visited[tempy][tempx] + 1;
					}
				}
			}
		}

	}

	public static void main(String[] args) throws IOException {

		// if(visited[from]+1 <= visited[go]) 진행

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int y = 0; y < n; y++) {
			String str = br.readLine();
			for (int x = 0; x < m; x++) {
				map[y][x] = Character.getNumericValue(str.charAt(x));

			}
		}

		bfs(0, 0);

	}

}
