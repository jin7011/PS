package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 미친로봇 {

	static double[] per = new double[4];
	static int[][] map = new int[40][40];
	static int[][] go = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
	static int n;
	static double res;
	static boolean[][] visited = new boolean[40][40];


	static void dfs(int y, int x, int cnt,double p) {
		
		if(cnt == n) {
			//if(!flag)
			res += p;
			return;
		}
		
		for(int q=0; q<4; q++) {
			
			int dy = y+go[q][0];
			int dx = x+go[q][1];
			
			if(!visited[dy][dx]) {
				visited[dy][dx] = true;
				double temp = p*per[q];
				dfs(dy,dx,cnt+1,temp);
				visited[dy][dx] = false;
			}
//			else { // 단순하지 않은 경우(갔던 곳을 또 갔음) -> true
//				flag = true;
//				return;
//				double temp = p*per[q];
//				dfs(dy,dx,cnt+1,temp,flag);
//			//	flag = false;
			//}
			
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		
		for (int x = 0; x < 4; x++) {
			per[x] = Integer.parseInt(st.nextToken()) * 0.01;
		}
		
		visited[15][15] = true;
		dfs(15,15,0,1);
		
		System.out.println(res);

	}

}
