package 프로그래머스;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class 타겟넘버 {

	public static void main(String[] args) {
		int[] numbers = { 1,1,1,1,1};
		int target = 5;
		int answer = 0;
		////////////////////////////////////////////////////////

		int sum = 0;
		ArrayList<ArrayList<Integer>> a = new ArrayList<ArrayList<Integer>>(numbers.length);

		for (int n : numbers) {
			sum += n;
		}

		a.add(new ArrayList<Integer>(sum));

		if(sum == target) {
			answer++;
			return;
		}
		
		a.get(0).add(sum);

		for (int y = 0; y < numbers.length; y++) {
			ArrayList<Integer> temp = new ArrayList<Integer>();
			for (int x = 0; x < a.get(y).size(); x++) {
				if(a.get(y).get(x) >= 0)
				temp.add(a.get(y).get(x));
				
				if(a.get(y).get(x) - numbers[y] * 2 >= 0)
				temp.add(a.get(y).get(x) - numbers[y] * 2);
			
				if(a.get(y).get(x) - numbers[y] * 2 == target )
					answer++;
			}
			a.add(temp);
		}

		System.out.println(answer);

	}

}
