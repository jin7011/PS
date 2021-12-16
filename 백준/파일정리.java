package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class 파일정리 {
	
	static int n;
	static TreeMap<String, Integer> map = new TreeMap<>();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
	
		n = Integer.parseInt(st.nextToken());
		
		for(int x=0; x<n; x++) {
			st = new StringTokenizer(br.readLine(),".");
			st.nextToken();
			String str = st.nextToken();
			
			map.put(str, map.getOrDefault(str, 0)+1);
		}
		
		for(Entry<String, Integer> e : map.entrySet()) {
			System.out.println(e.getKey()+" "+e.getValue());
		}
	}

}
