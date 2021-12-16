package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 로프 {

	static int[] arr;
	static int n,res;
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		arr = new int[n];
		
		for(int x=0; x<n; x++) {
			st = new StringTokenizer(br.readLine());
			arr[x] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr);
		
		for(int x=0; x<n; x++) {
			int biggerCnt = arr.length - x;
			
			res = Math.max(res, biggerCnt*arr[x]);
		}
		
		System.out.println(res);
	}

}
