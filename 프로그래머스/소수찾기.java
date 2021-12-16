package 프로그래머스;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class 소수찾기 {

	static boolean[] visited;
	static ArrayList<Integer> prime = new ArrayList<Integer>();
	static int[] res;

	static int check(int a) { // 1자리가 0이면 0 아니면 1반환

		int r = 1;

		for (int x = 1; x < 7; x++) {
			double k = Math.pow(10, x);
			if (a / k < 0)
				r = x;
		}

		if (a - r < 0)
			return 0;

		return 1;
	}
	
	static int cal(int n) {
		
		   if(n==0 || n==1) return 0;
	        for(int i=3; i<=(int)Math.sqrt(n); i+=2){
	            if(n%i==0) return 0;
	        }
	        return 1;
	}
	
	static int pcheck(ArrayList<Integer> p) {
		
		int cnt = 0;
		
		for(int a : p) {
			if(cal(a) !=0) cnt++;
		}
		
		return cnt;
		
	}

	static int ch(int[] arr) {

		String str = "";
		int res = 0;

		for (int x = 0; x < arr.length; x++)
			str += arr[x];

		res = Integer.parseInt(str);

		return res;
	}

	static void per(int[] arr, int cnt, int restric) {

		if (cnt == restric) {
			prime.add(ch(res));
			return;
		}

		for (int x = 0; x < arr.length; x++) {
			if (!visited[x]) {
				visited[x] = true;
				res[cnt] = arr[x];
				per(arr, cnt + 1, restric);
				visited[x] = false;
			}
		}
	}

	public static void main(String[] args) {

		String numbers;
		numbers = "011";
		int answer = 0;
		int[] arr = new int[numbers.length()];
		visited = new boolean[numbers.length()];

		for (int x = 0; x < numbers.length(); x++) {
			arr[x] = Character.getNumericValue(numbers.charAt(x));
		}

		for (int x = 1; x <= numbers.length(); x++) {
			res = new int[x];
			per(arr, 0, x);
		}
		
		Set<Integer> set = new HashSet<>(prime);
		prime = new ArrayList<>(set);

		System.out.println(pcheck(prime));

	}
}
