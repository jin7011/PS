package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class 친구 {

	static int n, res, answer;
	static String con = "";
	static ArrayList<Integer>[] arr;
	static boolean[] visited,count;

	static void dfs(int start, int cnt) {
		count[start] = true;
		visited[start] = true;

		if (cnt == 2) {
			visited[start] = false;
			return;
		}

		for (int x = 0; x < arr[start].size(); x++) {
			int go = arr[start].get(x);
			if (!visited[go]) {
				dfs(go, cnt + 1);
			}
		}
		visited[start] = false;

	}

	static int setcounted() {
		
		int cnt = 0;
		
		for (int x = 0; x < count.length; x++) {
			if (count[x]) {
				cnt++;
				count[x] = false;
			}
		}

		return cnt;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		arr = new ArrayList[n];
		count = new boolean[n];
		visited = new boolean[n];
		for (int x = 0; x < n; x++)
			arr[x] = new ArrayList<>();

		for (int y = 0; y < n; y++) {
			con = br.readLine();
			for (int x = 0; x < n; x++) {
				if (con.charAt(x) == 'Y' && !arr[y].contains(x) && !arr[x].contains(y)) {
					arr[y].add(x);
					arr[x].add(y);
				}
			}
		}

		for (int x = 0; x < n; x++) {
			dfs(x, 0);
			answer = Math.max(setcounted()-1, answer);

		}

		System.out.println(answer);

	}
	
	static void floyd() {
		
		int[][] a = new int[10][10];
		
		for(int k=0; k<a.length;k++) {
			for(int start=0; start<a.length;start++) {
				for(int end=0;end<a[start].length;end++) {
					if(start==end || start == k || end == k) continue;
					if(a[start][k] + a[k][end] < a[start][end])
						a[start][end] = a[start][k] + a[k][end];
				}
			}
		}
	}

}
