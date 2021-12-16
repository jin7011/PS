package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 블로그2 {
	
	static int n;
	static String str;
	static int Bcnt,Rcnt,res;
	static boolean[] visited;
	
	static void func(char RorB,int idx) {
		
		visited[idx] = true;
		
		if(idx == str.length()-1) {
			return;
		}

		char next = str.charAt(idx+1);
		
		if(next == RorB) {
			func(next,idx+1);
		}
		
		return;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		str = br.readLine();
		visited = new boolean[n];
		
//		for(int x=0; x<str.length();x++) {
//			char next = str.charAt(x);
//			
//			if(!visited[x] && next == 'R') {
//				func(next,x);
//				Rcnt++;
//			}
//			
//			if(!visited[x] && next == 'B') {
//				func(next,x);
//				Bcnt++;
//			}
//		}
		
		
		if(str.charAt(0) == 'R') Rcnt++;
		else Bcnt++;
		
		for(int x=1; x<str.length(); x++) {
			if(str.charAt(x-1) == str.charAt(x)) continue;
			else if(str.charAt(x) == 'R') Rcnt++;
			else Bcnt++;
		}
		
		res = Math.min(Bcnt+1, Rcnt+1);
		
		System.out.println(res);
	}

}
