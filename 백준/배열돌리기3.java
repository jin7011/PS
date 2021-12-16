package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 배열돌리기3 {

	static int[][] map = new int[301][301];
	static int n, m,r,group;
	static int[][] go = {{1,0},{0,1},{-1,0},{0,-1}};
	
	static boolean isrange(int y,int x,int g) {
		return x>=g && x<(m-g) && y>=g && y<(n-g);
	}
	
	static void func(int group) {
		
		int dir = 0;
		
		for(int g=0; g<group; g++) {
			int dx = g;
			int dy = g;
			int pre = map[dy][dx];
			
			while(dir<4) {
				
				dy = dy + go[dir][0];
				dx = dx + go[dir][1];
				
				if(isrange(dy, dx, g)) {
					int temp = map[dy][dx];
					map[dy][dx] = pre;
					pre = temp;
				}else {
					dy=dy-go[dir][0];
					dx=dx-go[dir][1];
					dir++;
				}
				
			}
			dir = 0;
		}
		
	}
	
	static void show() {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				System.out.print(map[y][x] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		for (int y = 0; y < n; y++) {
			st = new StringTokenizer(br.readLine());
			for (int x = 0; x < m; x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
			}
		}
		
		group = Math.min(n, m)/2;
		
		for(int x=0; x<r; x++) {
			func(group);
		}
		
//		func(group);
		show();

	}

}
