package 프로그래머스;

import java.util.Arrays;

public class k번째수 {

	static int func(String a,int n) {
		
		int[] arr = new int[a.length()];

		for (int x = 0; x < a.length(); x++) 
			arr[x] = Character.getNumericValue(a.charAt(x));
		
		Arrays.sort(arr);
		
		return arr[n-1];
	}

	public static void main(String[] args) {

		int[] array = { 1, 5, 2, 6, 3, 7, 4 };
		int[][] commands = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };
		int[] answer = new int[commands.length];

		
		for (int y = 0; y < commands.length; y++) {
			int temp[] = new int[commands[y][1]-commands[y][0] +1];
			for(int x=0; x<temp.length; x++)
				temp[x] = array[(commands[y][0]-1) + x];
			Arrays.sort(temp);
			answer[y] = temp[commands[y][2]-1];
			
		}
		

	}

}
