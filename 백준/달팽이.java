package ¹éÁØ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ´ÞÆØÀÌ {

	static int n, k, resy = 1, resx = 1, y = 1, x = 1;
	static int[][] map;
	static boolean[][] visited;

	static boolean isrange(int y, int x) {
		return y >= 1 && y <= n && x >= 1 && x <= n;
	}

	static void go(int n) {
		switch (n) {
		case 1:
			y = y + 1;
			break;
		case 2:
			x = x + 1;
			break;
		case 3:
			y = y - 1;
			break;
		case 4:
			x = x - 1;
			break;
	
		default:
			throw new IllegalArgumentException("Unexpected value: " + n);
		}
	}

	static void bfs() {

		while(true)
		for (int q = 1; q <= 4; q++)
			while (true) {

				int temp = map[y][x];
				int dy = y;
				int dx = x;
				go(q);

				if (isrange(y, x) && !visited[y][x]) {
					visited[y][x] = true;
					map[y][x] = temp - 1;
					if (map[y][x] == k) {
						resy = y;
						resx = x;
					}
					if (x == (n + 1) / 2 && y == x)
						return;

				} else {
					y = dy;
					x = dx;
					break;
				}
			}

	}

	static void func() {

		map[1][1] = n * n;
		visited[1][1] = true;

		bfs();

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());
		map = new int[n + 1][n + 1];
		visited = new boolean[n + 1][n + 1];

		func();

		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= n; x++) {
				System.out.print(map[y][x] + " ");
			}
			System.out.println();
		}

		System.out.println(resy + " " + resx);

	}

}
