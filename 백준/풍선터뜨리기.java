package πÈ¡ÿ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class «≥º±≈Õ∂ﬂ∏Æ±‚ {
	
	static int n;
	static String str = "";
	static Deque<pair> deq = new ArrayDeque<>();
	
	static class pair{
		int idx,num;
		
		pair(int idx,int num){
			this.idx = idx;
			this.num = num;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int x=1; x<=n; x++) {
			deq.add(new pair( x, Integer.parseInt( st.nextToken() )));
		}
		
		int dir = deq.peekFirst().num;
		int idx = deq.pollFirst().idx;
		str += idx + " ";
		
		while(!deq.isEmpty())
		{
				if(dir >= 0) { //ø¿∏•¬ 
					for(int x=0; x<dir; x++)
						deq.addLast(deq.pollFirst());
					dir = deq.peekLast().num;
					idx = deq.pollLast().idx;
					str += idx + " ";
				}
				
				else if(dir < 0) { //øﬁ¬ 
					for(int x=0; x<Math.abs(dir); x++)
						deq.addFirst(deq.pollLast());
					dir = deq.peekFirst().num;
					idx = deq.pollFirst().idx;
					str += idx + " ";
				}
		}
		
		System.out.println(str);
		
	}

}
