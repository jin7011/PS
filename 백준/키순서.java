package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 키순서 {

	static boolean[] visited;
	static int n, m, res,answer;
	//static ArrayList<Integer>[] arr;
	//static ArrayList<Integer>[] arr2;
	static ArrayList<Integer>[][] arr3;

	static public int dfs(int dir, int start) {

		int res = 1;
		
		visited[start] = true;

//		for (int x = 0; x < arr[start].size(); x++) {
//
//			int go = arr[start].get(x);
//			if (!visited[go]) {
//				res += dfs(arr, go);
//			}
//		}
		
		for(int go : arr3[dir][start]) {
			if(!visited[go]) {
				res += dfs(dir,go);
			}
		}
		
		visited[start] = false;
		
		return res;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		visited = new boolean[n + 1];
		//arr = new ArrayList[n + 1];
		//arr2 = new ArrayList[n + 1];
		arr3 = new ArrayList[2][n+1];

//		for (int x = 1; x <= n; x++) {
////			arr[x] = new ArrayList<Integer>();
////			arr2[x] = new ArrayList<Integer>();
//	}
//		
		for(int y=0; y<2; y++)
			for(int x=1; x<=n;x++) {
				arr3[y][x] = new ArrayList<Integer>();
			}
		
		for (int x = 0; x < m; x++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			arr3[0][a].add(b);
			arr3[1][b].add(a);

			//arr[a].add(b);
			//arr2[b].add(a);
		}

		for (int x = 1; x <= n; x++) {
			if(dfs(0, x) + dfs(1,x) == n-1) answer++;
		}
		
		System.out.println(answer);

	}

}
