package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 센서 {

	
	static int[] arr;
	static int n,k,res;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		k =  Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		arr = new int[n];
		
		for(int x=0; x<n; x++)
			arr[x] = Integer.parseInt(st.nextToken());
		
		Arrays.sort(arr);
				
		for(int x=1; x<n; x++) {
			arr[x-1] = arr[x]-arr[x-1];
		}
		
		Arrays.sort(arr);
		
		for(int x=0; x<n-k; x++) {
			res+=arr[x];
		}
	
		System.out.println(res);
	}
}
