package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class 회의실 {

	static int res;
	static List<pair> arr = new ArrayList<>();
	
	static class pair implements Comparable<pair>{
		
		int start,end;
		
		pair(int s,int e){
			this.start = s;
			this.end = e;
		}

		@Override
		public int compareTo(pair o) {
			if(end == o.end) {
				return start - o.start;
			}
			else
			return end-o.end;
		}

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		for (int x = 0; x < n; x++) {
			st = new StringTokenizer(br.readLine());
			arr.add(new pair(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())));
		}
		
		Collections.sort(arr);
		
		int start;
		int end = arr.get(0).end;

		for(int x=1; x<arr.size();x++) {
			
			start = arr.get(x).start;
			
			if(end <= start) {
				res++;
				end = arr.get(x).end;
				//System.out.println(arr.get(x).start +" "+arr.get(x).end);
			}
			
		}
		
		System.out.println(res+1);

	}

}