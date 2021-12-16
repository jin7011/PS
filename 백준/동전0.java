package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 동전0 {

		static int n, money, res = 0, end;
		static int[] arr;

		public static void main(String[] args) throws IOException {

			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(br.readLine());

			n = Integer.parseInt(st.nextToken());
			money = Integer.parseInt(st.nextToken());
			arr = new int[n];
			int idx = 0;

			for (int x = 0; x < n; x++) {
				st = new StringTokenizer(br.readLine());
				arr[x] = Integer.parseInt(st.nextToken());
				if (money / arr[x] > 0)
					idx = x;
			}

			for (int x = idx; x >= 0; x--) {
				
				if(money == 0) 
					break;
				
				if(money/arr[x] > 0) { //사용한 해당 화폐가 1개 이상이면,
					res += money/arr[x]; 
					money %= arr[x];
				}
				
			}
			
			System.out.println(res);

		}

}
