package 백준;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingDeque;

public class 이모티콘 {

	static int[][] map = new int[1001][1001];
	static boolean[][] visited = new boolean[1001][1001];
	static int s;
	static Queue<pair> que = new LinkedBlockingDeque<>();

	static class pair {
		int y, x, cnt;

		public pair(int y, int x, int cnt) {
			this.y = y;
			this.x = x;
			this.cnt = cnt;
		}
	}

	static boolean isrange(int y, int x) {
		return y > 0 && y <= s && x > 0 && x <= 1000 && y <= 1000;
	}

	static void bfs(int y, int x, int cnt) {

		que.add(new pair(y, x, cnt));
		visited[y][x] = true;

		while (!que.isEmpty()) {

			y = que.peek().y;
			x = que.peek().x;
			cnt = que.poll().cnt;

			if (y == s) {
				System.out.println(cnt);
				return;
			}

			for (int q = 0; q < 3; q++) { // 0은 저장 1은 붙혀넣기 3은 삭제

				switch (q) {
				case 0: {

					int dx = y;
					int dy = y;

					if (isrange(dy, dx)) {
						if (!visited[dy][dx]) {
							visited[dy][dx] = true;
							que.add(new pair(dy, dx, cnt + 1));
						}
					}

					break;

				}
				case 1: {

					int dy = y + x;
					int dx = x;

					if (isrange(dy, dx)) {
						if (!visited[dy][dx]) {
							visited[dy][dx] = true;
							que.add(new pair(dy, dx, cnt + 1));
						}
					}

					break;

				}
				case 2: {

					int dy = y - 1;
					int dx = x;

					if (isrange(dy, dx)) {
						if (!visited[dy][dx]) {
							visited[dy][dx] = true;
							que.add(new pair(dy, dx, cnt + 1));
						}
					}
					break;
				}
				default:
					System.out.println("ㅠㅠ");
					break;
				}
			}
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = Integer.parseInt(br.readLine());

		bfs(1, 0, 0); // 1개 가지고있고 0개의 복사본, 0번의 시도

	}
}

