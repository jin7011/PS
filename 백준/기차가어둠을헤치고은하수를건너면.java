package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 기차가어둠을헤치고은하수를건너면 {

	static int n, m;
	static int[][] train = new int[100001][21];

	static void takein(int num, int seat) {

		if (train[num][seat] == 1)
			return;
		else {
			train[num][seat] = 1;
		}

	}

	static void takeoff(int num, int seat) {

		if (train[num][seat] == 0)
			return;
		else {
			train[num][seat] = 0;
		}

	}

	static void goback(int num) {
		
		if (train[num][20] == 1) {
			train[num][20] = 0;
		}

		for (int seat = 19; seat >= 1; seat--) {
			if (train[num][seat] == 1) {
				train[num][seat] = 0;
				train[num][seat+1] = 1;
			}
		}

	}

	static void gofront(int num) {
		
		if (train[num][1] == 1) {
			train[num][1] = 0;
		}

		for (int seat = 2; seat <= 20; seat++) {
			if (train[num][seat] == 1) {
				train[num][seat] = 0;
				train[num][seat-1] = 1;
			}
		}

	}

	public static boolean issame(int[] arr1, int[] arr2) {
		
		boolean flag = true;
		
		for(int x=1; x<=20; x++) {
			int a1 = arr1[x];
			int a2 = arr2[x];
			
			if(a1!=a2) {
				flag = false;
				break;
			}
		}
		
		return flag;
	}

	//하지만 중복체크할 때 그냥 set에 집어넣고 set의 size를 보는 것도 괜찮다.
	private static int check() {
		
		int cnt = 1; boolean flag = false;

		for (int cur = 2; cur <= n; cur++) {
			for (int num = cur-1; num >= 1; num--) {
				if(issame(train[cur],train[num])) {
					flag = true;
					break;
				}
			}
			if(!flag) cnt++;
			else flag = false;
		}

		return cnt;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int x = 0; x < m; x++) {
			st = new StringTokenizer(br.readLine());
			int order = Integer.parseInt(st.nextToken());

			if (order == 1) { // 탑승
				int num;
				int seat;
				num = Integer.parseInt(st.nextToken());
				seat = Integer.parseInt(st.nextToken());
				
				takein(num, seat);
			}

			if (order == 2) { // 하차
				int num;
				int seat;
				num = Integer.parseInt(st.nextToken());
				seat = Integer.parseInt(st.nextToken());
				
				takeoff(num, seat);
			}

			if (order == 3) { // 뒤로
				int num;
				num = Integer.parseInt(st.nextToken());
				
				goback(num);
			}
			if (order == 4) { // 앞으로
				int num;
				num = Integer.parseInt(st.nextToken());
				
				gofront(num);
			}

		}
		
		System.out.println(check());
		
	}

	
}
