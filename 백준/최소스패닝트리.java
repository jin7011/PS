package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class 최소스패닝트리 {

	static int v, e,sum;
	static int[] parent;
	static ArrayList<tuple> arr = new ArrayList<>();

	static class tuple implements Comparable<tuple> {

		int start, end, dis;

		tuple(int start, int end, int dis) {
			this.start = start;
			this.end = end;
			this.dis = dis;
		}

		@Override
		public int compareTo(tuple o) {
			return dis - o.dis;
		}

	}

	static int getP(int n) {

		if (n == parent[n])
			return n;

		return parent[n] = getP(parent[n]);
	}

	static void union(int a, int b) {

		a = getP(a);
		b = getP(b);

		if (a > b)
			parent[a] = b;
		else
			parent[b] = a;

	}

	static int isunion(int a, int b) {

		a = getP(a);
		b = getP(b);
		
		if(a==b)
			return 1;
		else
			return -1;

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());

		parent = new int[v + 1];
		for(int x=1; x<=v; x++)
			parent[x] = x;

		for (int x = 0; x < e; x++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int distance = Integer.parseInt(st.nextToken());

			arr.add(new tuple(start, end, distance));

		}
		
		Collections.sort(arr);

		for(tuple t : arr) {
			if(isunion(parent[t.start],parent[t.end]) == -1) {
				union(t.start,t.end);
				sum += t.dis;
			}
		}
		
		System.out.println(sum);

	}

}
