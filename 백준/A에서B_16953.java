package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A에서B_16953 {
	
	static int start, end, res = 0;

	static boolean isright(int n) {
		String str = String.valueOf(n);
		boolean flag2 = (n % 2) != 0;
		boolean flag = str.charAt(str.length() - 1) != '1';
		return flag && flag2;
	}


	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		start = Integer.parseInt(st.nextToken());
		end = Integer.parseInt(st.nextToken());
		
		while(start < end) {
			
			if(isright(end)) {
				System.out.println(-1);
				return;
			}
			
			if(end%2 == 0) {
				end /=2;
			}else {
				String str = String.valueOf(end);
				if(str.charAt(str.length() - 1) == '1') {
					str = str.substring(0,str.length()-1);
					end = Integer.parseInt(str);
				}
			}
			
			if(start > end)
			{
				System.out.println(-1);
				return;
			}
			
			res++;
		}

		System.out.println(res+1);
	}

}
