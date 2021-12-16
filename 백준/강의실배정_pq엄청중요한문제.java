package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 강의실배정_pq엄청중요한문제 {

	static class pair implements Comparable<pair> {

		int start, end;

		pair(int s, int e) {
			this.start = s;
			this.end = e;
		}

		@Override
		public int compareTo(pair o) {

			if (start == o.start)
				return end - o.end;
			else
				return start - o.start;
		}

	}

	static int res, n;
	static boolean[] visited;
	static List<pair> arr = new ArrayList<>();
	static PriorityQueue<Integer> pq = new PriorityQueue<>(); //가장 빨리 끝나는 얘를 top으로

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		visited = new boolean[n];

		for (int x = 0; x < n; x++) {
			st = new StringTokenizer(br.readLine());
			arr.add(new pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		
		Collections.sort(arr);
		pq.add(arr.get(0).end);
		
		for(int x= 1; x<n;x++) {
			
			int start = arr.get(x).start;
			int end = arr.get(x).end;
			
			if(pq.peek() > start) {
				pq.add(end);
			}else {
				pq.poll();
				pq.add(end);
			}
					
		}
		
		System.out.println(pq.size());
		

	}
}
