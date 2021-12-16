package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 빙고 {

	static int[][][] map = new int[5][5][2];
	static int bingo, ans;

	static boolean func() {

		bingo = 0;
		int check = 0;
		
		// 가로
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				if (map[y][x][1] != 0)
					check++;
			}
			if (check == 5) {
				bingo++;
			}
			check = 0;
		}
		// 세로
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				if (map[y][x][1] != 0)
					check++;
			}
			if (check == 5) {
				bingo++;
			}
			check = 0;
		}
		
		//대각선
		for (int q = 0; q < 5; q++) {
			if (map[q][q][1] != 0)
				check++;
		}
		if (check == 5) {
			bingo++;
		}
		check = 0;


		//대각선
		for (int q = 0; q < 5; q++) {
			if (map[q][4 - q][1] != 0)
				check++;
		}
		if (check == 5) {
			bingo++;
		}
		check = 0;
		
		
		//결과
		if (bingo >= 3) {
			return true;
		} else {
			return false;
		}

	}

	static void find(int n) {

		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				if (map[y][x][0] == n)
					map[y][x][1] = 1;
			}
		}

	}
	
	static void show() {
		for (int y = 0; y < 5; y++) {
			System.out.println();
			for (int x = 0; x < 5; x++) {
				System.out.print(map[y][x][1] + " ");
			}
		}
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		for (int y = 0; y < 5; y++) {
			st = new StringTokenizer(br.readLine());
			for (int x = 0; x < 5; x++) {
				map[y][x][0] = Integer.parseInt(st.nextToken());
			}
		}

		for (int y = 0; y < 5; y++) {
			st = new StringTokenizer(br.readLine());
			for (int x = 0; x < 5; x++) {
				int next = Integer.parseInt(st.nextToken());
				ans++;
				find(next);
			
				if (func()) {
//					show();
					System.out.println(ans);
					return;
				}
//				else
//					show();
//				System.out.println();

			}
		}

	
	}
}