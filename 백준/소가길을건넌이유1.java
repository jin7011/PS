package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 소가길을건넌이유1 {

	static int n, res;
	static int[] arr;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		arr = new int[n + 1];

		for (int x = 0; x < arr.length; x++) {
			arr[x] = -1;
		}

		for (int x = 1; x <= n; x++) {
			st = new StringTokenizer(br.readLine());
			int so = Integer.parseInt(st.nextToken());
			int pos = Integer.parseInt(st.nextToken());
			if (arr[so] != -1 && arr[so] != pos) { //길이 한번이라도 포착이 되었고 위치가 바뀌었다면
				res++;
				arr[so] = pos;
			}else if(arr[so] == -1)
				arr[so] = pos;
		}
		
		System.out.println(res);
	}

}
