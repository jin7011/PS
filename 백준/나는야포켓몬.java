package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class 나는야포켓몬 {

	static int n,m;
	static String str;
	static HashMap<String, Integer> hash = new HashMap<>();
	static HashMap<Integer, String> hash2 = new HashMap<>();
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		for(int x=1; x<=n; x++) {
			str = br.readLine();
			hash.put(str, x);
			hash2.put(x, str);
		}
		
		for(int x=0; x<m; x++) {
			String a = br.readLine();
			if(Character.isAlphabetic(a.charAt(0))) {
				System.out.println(hash.get(a));
			}else {
				System.out.println(hash2.get(Integer.parseInt(a)));
			}
		}
	}

}
