package 프로그래머스;

import java.util.ArrayList;
import java.util.Collections;

public class 모의고사 {

	static class pair implements Comparable<pair> {

		int idx, b;

		public pair(int idx, int b) {
			this.idx = idx;
			this.b = b;
		}

		@Override
		public int compareTo(pair o) {
			return b - o.b;
		}

	}

	public static void main(String[] args) {

		int[] user1 = { 1, 2, 3, 4, 5 };
		int[] user2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
		int[] user3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

		int[] answers = { 1, 2, 3, 4, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		int[] answer = { 0, 0, 0, 0 };

		ArrayList<pair> arr = new ArrayList<pair>();
		ArrayList<Integer> Answer = new ArrayList<Integer>();

		for (int x = 0; x < answers.length; x++) {
			if (answers[x] == user1[x % 5]) {
				answer[1]++;
			}
			if (answers[x] == user2[x % user2.length]) {
				answer[2]++;
			}
			if (answers[x] == user3[x % user3.length]) {
				answer[3]++;
			}
		}
		
		int max = Math.max( answer[1], Math.max(answer[2], answer[3]));
		
		for(int x=1; x<4; x++) {
			if(max == answer[x]) {
				Answer.add(x);
			}
		}
		
		for (int a : Answer) {
			System.out.print(a + " ");
		}

	}
}
