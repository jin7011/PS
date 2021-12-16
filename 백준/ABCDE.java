package น้มุ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class ABCDE {

	static ArrayList<Integer>[] arr;
	static boolean[] visited;
	static int aa, res = 0;
	static boolean flag = false;

	static void dfs(List<Integer>[] arr, int start,int cnt) {
		
		if(cnt>=5) {
			flag = true;
			return;
		}
			
		visited[start] = true;
		
		for (int x = 0; x < arr[start].size(); x++) {
			int des = arr[start].get(x);
			if (!visited[des]) 
				dfs(arr, des,cnt+1);
		}
		
		visited[start] = false;
	}

	public static void main(String[] args) throws IOException {

		int n, m, a, b;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new ArrayList[n];
		visited = new boolean[n];

		for (int x = 0; x < n; x++)
			arr[x] = new ArrayList<>();

		for (int x = 0; x < m; x++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			arr[a].add(b);
			arr[b].add(a);
		}

		for (int x = 0; x < m; x++) 
		{
			if(flag) {
				res++;
				break;
			}
				dfs(arr, x,1);
		}
				
		System.out.println(res);

	}

}
