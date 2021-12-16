package 프로그래머스;

import java.util.Arrays;
import java.util.Collections;

public class H_index {

	public static void main(String[] args) {
		
		int answer = 0;
		int[] a = {3, 0, 6, 1, 5};
		int h = a.length;
		Arrays.sort(a);
		
		for(int x=0; x<a.length; x++) {
			h= a.length-x;
			if(h <= a[x]) {
				answer = h;
				break;
			}
		}
		

		
		
		System.out.println(answer);
	}

}
