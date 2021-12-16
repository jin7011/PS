package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class 중복가능한permutation {

	static ArrayList<String> arr = new ArrayList<>();
	static String[] str = { "E", "W", "N", "S" };
	static String[] res;

	static public void per(int n, int cnt) {

		if(n==cnt) {
			String temp = "";
			for(String s : res)
				temp += s;
			
			arr.add(temp);
			System.out.println(temp);
			return;
		}
		
		for (int x = 0; x < str.length; x++) {
		
			res[cnt] = str[x];
			per(n,cnt+1);
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		res = new String[n];
		for(int x=0; x<n; x++)
			res[x] = "";
		
		per(n,0);
	}

}
