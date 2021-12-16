package น้มุ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class บ๘นฐ {

	static int ny, nx;
	static int[] map = new int[501];

	static int find(int start, int high) {

		if (start == nx)
			return start;
		int most = 0;
		int mostidx = 0;

		for (int x = start + 1; x <= nx; x++) {
			int next = map[x];

			if (most <= next) {
				most = next;
				mostidx = x;
			}

			if (next >= high) {
				mostidx = x;
				break;
			}
		}

		return mostidx;

	}

	static int sumf(int start, int end) {
		int sum = 0;
		int gap_idx = end - (start+1);
		int gap_h = map[start] - map[end];
		if (gap_h < 0)
			gap_h = 0;

		for (int x = start + 1; x < end; x++) {
			if(map[start]-map[x] >= 0)
			sum += map[start] - map[x];
		}

		return sum - (gap_idx * gap_h);
	}

	static int func() {
		int sum = 0;

		for (int x = 1; x < nx; x++) {
			int end = find(x, map[x]);
			sum += sumf(x, end);
			x = end-1;
		}

		return sum;
	}
	
	static int func2() {
		int sum =0;
		
		for(int x=1; x<=nx; x++) {
			int lmax = 0;
			int rmax = 0;
			for(int lx = x-1; lx>=1; lx--) lmax = Math.max(lmax, map[lx]);
			for(int rx = x+1; rx<= nx; rx++) rmax = Math.max(rmax, map[rx]);
			
			if(Math.min(lmax, rmax)-map[x] <= 0)
				continue;
			else
				sum += Math.min(lmax, rmax)-map[x];
		}
		
		return sum;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		ny = Integer.parseInt(st.nextToken());
		nx = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		for (int x = 1; x <= nx; x++) {
			int y = Integer.parseInt(st.nextToken());

			for (int q = 0; q < y; q++) {
				map[x] = y;
			}
		}

//		System.out.println(func());
		System.out.println(func2());

	}

}
