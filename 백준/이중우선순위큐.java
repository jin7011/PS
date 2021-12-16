package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class 이중우선순위큐 {
	
	//d 1 최대값삭제
	//d -1 최소값 삭제
	//비어있을 때 d연산 무시
	//남은 최대값과 최솟값 비어있으면 EMPTY출력
	
	static int testcase,k;
	static char order;
	static TreeMap<Long,Integer> map = new TreeMap<>();
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		testcase = Integer.parseInt(st.nextToken());
		
		for(int x=0; x<testcase; x++) {
			
			k = Integer.parseInt(st.nextToken());
			
			for(int q=0; q<k; q++) {

				st = new StringTokenizer(br.readLine());
				order = (char)st.nextElement();
				
				if(order == 'D') {
					
				}
				
				else if(order == 'I') {
					
				}
				
			}
			
			
		}
		
	}

}
