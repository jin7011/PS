package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 스위치켜고끄기 {

	static int bulb, students;
	static int[] arr;

	private static void change(int gender, int num) {

		if (gender == 1) {

			for (int x = num; x <= bulb; x += num) {
				if (arr[x] == 1)
					arr[x] = 0;
				else
					arr[x] = 1;
			}
		}

		if (gender == 2) {

			int left = num-1;
			int right = num+1;
			
			while(true) {
				if((left)<1 || (right)> bulb) 
					break;
				if(arr[left] != arr[right])
					break;
				left--;
				right++;
			}
			
			left++;
			right--;
			
			for(int x= left; x<=right; x++) {
				if (arr[x] == 1)
					arr[x] = 0;
				else
					arr[x] = 1;
			}

		}
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		bulb = Integer.parseInt(st.nextToken());
		arr = new int[101];

		st = new StringTokenizer(br.readLine());

		for (int x = 1; x <= bulb; x++) {
			arr[x] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(br.readLine());
		students = Integer.parseInt(st.nextToken());

		for (int x = 0; x < students; x++) {
			st = new StringTokenizer(br.readLine());

			int gender = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());

			change(gender, num);
		}
		
		for (int x = 1; x <= bulb; x++) {
			System.out.print(arr[x] + " ");
			if(x%20 == 0) System.out.println();
		}

	}

}
