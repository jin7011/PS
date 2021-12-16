package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 오목 {

	static int[][] map = new int[20][20];
	static int[][] go = { { -1, 1 }, { 1, 0 }, { 1, 1 }, { 0, 1 } };
	static int[][] check = { { 1, -1 }, { -1, 0 }, { -1, -1 }, { 0, -1 } };

	static class pair {
		int y, x;

		pair(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	static boolean isrange(int y, int x) {
		return y >= 1 && y <= 19 && x >= 1 && x <= 19;
	}

	static boolean check(int y, int x, int q) {
		int cur = map[y][x];
		int dy = y + check[q][0];
		int dx = x + check[q][1];

		if (isrange(dy, dx) && map[dy][dx] == cur)
			return false;
		else
			return true;

	}

	static pair func(int sy, int sx, int cur) {

		pair p = null;
		int cnt = 1;
		int y = sy;
		int x = sx;

		for (int q = 0; q < 4;) {

			int dy = sy + go[q][0];
			int dx = sx + go[q][1];

			if (isrange(dy, dx) && map[dy][dx] == cur) {
				cnt++;
				sy = dy;
				sx = dx;
				continue;
			} else {
				if (cnt == 5) {
					if (check(y, x, q)) {
						p = new pair(y, x);
						break;
					}else {
						cnt = 1;
						q++;
						sy = y;
						sx = x;
					}
				} else {
					cnt = 1;
					q++;
					sy = y;
					sx = x;
				}
			}
		}

		return p;

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		for (int y = 1; y < 20; y++) {
			st = new StringTokenizer(br.readLine());
			for (int x = 1; x < 20; x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
			}
		}

		for (int x = 1; x < 20; x++) {
			for (int y = 1; y < 20; y++) {
				int next = map[y][x];
				if (next != 0) {
					pair p = func(y, x, next);
					if (p != null) {
						System.out.println(next);
						System.out.println(p.y + " " + p.x);
						return;
					}
				}

			}
		}

		System.out.println(0);
//		
//		int next = map[3][2];
//		if(next != 0) {
//			pair p = func(3,2,next);
//			if(p != null) {
//				System.out.println(next);
//				System.out.println(p.y+" "+p.x);
//				return;
//			}
//		}
//		

	}

}
