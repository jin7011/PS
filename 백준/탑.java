package น้มุ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class ลพ {

	static class pair{
		int idx,high;
		
		pair(int h,int i){
			this.idx = i;
			this.high = h;
		}
	}
	
	static int n;
	static int[] arr;
	static Stack<pair> stk = new Stack<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {

		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr= new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		for(int x=1; x<=n; x++) {
			arr[x] = Integer.parseInt(st.nextToken());
		}
		
		for(int x=1; x<=n; x++) {
			
			int high = arr[x];
			
			if(stk.isEmpty()) {
				stk.add(new pair(high,x));
				arr[x] = 0;
			}
			else {
				while(true) {
					if(stk.isEmpty()) {
						stk.add(new pair(high,x));
						arr[x] = 0;
						break;
					}
					if(high < stk.peek().high) {
						arr[x] = stk.peek().idx;
						stk.add(new pair(high,x));
						break;
					}else {
						stk.pop();
					}
				}
			}
		}
		
		for(int x=1; x<=n; x++)
			System.out.print(arr[x]+" ");
		
		
	}

}
