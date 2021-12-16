package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class 달력20207 {

	static int[][] map = new int[1002][367];
	static int s, e, n, max;
	static ArrayList<pair> arr = new ArrayList<>();

	static class pair implements Comparable<pair> {

		int s, e;

		pair(int s, int e) {
			this.s = s;
			this.e = e;
		}

		@Override
		public int compareTo(pair o) {
			if (s == o.s) {
				return o.e - e;
			} else
				return s - o.s;
		}

	}

	static int check(int start, int end) { //몇 칸까지 내려가야하는지 계산하고

		int layer = 1;

		for (int y = 1; y <= n; y++) {
			boolean flag = false;
			for (int x = start; x <= end; x++) {

				int cur = map[y][x];

				if (cur == 1) {
					flag = true;
					break;
				}
			}

			if (!flag) {
				layer = y;
				break;
			}
		}

		return layer;
	}

	static void func(int start, int end) { //계산한 곳까지 채움

		int y = check(start, end);

		for (int x = start; x <= end; x++) {
			map[y][x] = 1;
		}
	}

	static int cal() { // 마지막으로 계산

		int sum = 0;
		int dy = 0;
		int dx = 0;
		boolean flag=false;	
		for (int x = 1; x <= max; x++) {
			flag = false;
			for (int y = 1; y <= n; y++) {
				if (map[y][x] == 1) {
					flag = true;
					dy = Math.max(dy, y);
				}
			}
			if (!flag) {
				sum += dy * dx;
				dy = 0;
				dx = 0;
			} else
				dx++;
		}
		//비어있는 칸이 있는데도 계산하려니까 for문을 빠져나오기
		//때문에 마지막 연산은 for문 밖에서 해주어야한다.
		if(flag) {
			sum+=dy*dx;
		}

		return sum;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());

		for (int x = 0; x < n; x++) {
			st = new StringTokenizer(br.readLine());

			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());

			max = Math.max(max, e);

			arr.add(new pair(s, e));
		}

		Collections.sort(arr);

		for (pair p : arr) {

			int start = p.s;
			int end = p.e;

			func(start, end);
		}

		System.out.println(cal());
	}
}
