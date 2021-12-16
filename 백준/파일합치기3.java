package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 파일합치기3 {
	
	static int t,n;
	static Long temp,res;
	static PriorityQueue<Long> pq;
	
	public static void main(String[] args) throws IOException {

		// if(visited[from]+1 <= visited[go]) 진행

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		t= Integer.parseInt(st.nextToken());
		
		for(int x=0; x<t; x++) {
			res =(long) 0;
			pq = new PriorityQueue<>();
			st = new StringTokenizer(br.readLine());
			n= Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int q=0; q<n; q++) {
				pq.add(Long.parseLong((st.nextToken())));
			}

			for(int q=0; q<n-1; q++) {
				temp = (long) 0;
				temp += pq.poll();
				temp += pq.poll();
				pq.add(temp);
				
				res+=temp;
				
				
			}
			System.out.println(res);
		}
	}
}
