package ¹éÁØ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class n°úm3 {
	
	static int n,m;
	static int[] ch = new int[8];
	static boolean[] visited = new boolean[8];

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		dfs(0);
	}

	private static void dfs(int cnt) {
		
		if(cnt == m) {
			String str = "";
			for(int x=0; x<m;x++) {
				str += ch[x]+" ";
			}
			System.out.println(str);
			return;
		}
		
		for(int x=1; x<=n; x++) {
			
			if(cnt == 0) {
				ch[cnt] = x;
				dfs(cnt+1);
			}
			else if(cnt >= 1 && ch[cnt-1] <= x) {
				ch[cnt] = x;
				dfs(cnt+1);
			}
			
		}
	}

}
