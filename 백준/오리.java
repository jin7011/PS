package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class 오리 {

	static String str;
	static int res;
	static boolean[] visited;

	static void isright() {

		ArrayList<Character> arr = new ArrayList<>();
		char[] ch = { 'q', 'u', 'a', 'c', 'k' };
		int idx = 0;
		int res = 0;

		for (int x = 0; x < str.length(); x++) {
			arr.add(str.charAt(x));
		}

		while (true) {

			for (int x = 0; x < arr.size(); x++) {
				char next = arr.get(x);
				char wanna = ch[idx];

				if (next == wanna) {
					idx = (idx + 1) % 5;
					arr.remove(x);
					x--;
				}
			}
			
			if (idx == 0)
				res++;
			else
			{
				System.out.println(-1);
				return;
			}
			if(arr.isEmpty()) {
				System.out.println(res);
				return;
			}
			
		}
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();
		
		if(str.length()%5 !=0 || str.charAt(0)!='q') {
			System.out.println(-1);
			return;
		}
		
		isright();

	}

}
