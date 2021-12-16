package 프로그래머스;

import java.util.Arrays;













public class 가장큰수2 {

	public static void main(String[] args) {
		
		int[] numbers = {3, 30, 34, 5, 9};
		String[] str = new String[numbers.length];
		
		for(int x=0; x<numbers.length; x++) {
			str[x] = String.valueOf(numbers[x]);
		}
		
		Arrays.sort(str, (o1,o2) -> (o2+o1).compareTo(o1+o2));
		
		String answer = ""; 
		
		if(str[0].equals(str[1]) && str[0].equals(0)) {
			answer = "0";
		}else
			for(String s : str)
				answer += s;
		
	}

}
