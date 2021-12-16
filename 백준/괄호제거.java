package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Stack;

public class 괄호제거 {

	static Stack<Integer> stk = new Stack<Integer>();
	static String str;
	static Set<String> removedSet = new HashSet<String>();
	static char[] ch;
	static ArrayList<pair> arr = new ArrayList<>();
	
	static class pair{

		int Fidx,Ridx;
		
		pair(int f,int r){
			this.Fidx = f;
			this.Ridx = r;
		}
	}
	
	static void func(int cnt,char[] ch) {
		
		if(cnt>=arr.size()) {
			String removed = new String(ch);
			removed = removed.replaceAll(" ","");
			removedSet.add(removed);
		}
		else {
			pair p = arr.get(cnt);
			int left = p.Fidx;
			int right = p.Ridx;
			
			ch[left] = ' ';
			ch[right] = ' ';
			func(cnt+1,ch);

			ch[left] = '(';
			ch[right] = ')';
			func(cnt+1,ch);
			
		}
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();

		ch = new char[str.length()];

		for (int x = 0; x < str.length(); x++) {
			ch[x] = str.charAt(x);
		}

		for(int x=0; x<ch.length; x++) {
			char next = ch[x];
			
			if(next == '(')
				stk.add(x);
			else if(next == ')')
				arr.add(new pair(stk.pop(),x));
		}
		
		func(0,ch);
		
		//removedSet.remove(str);
		
		List<String> res = new ArrayList(removedSet);
		
		//Collections.sort(res,Comparator.reverseOrder());
		Collections.sort(res);
		
		for(String s : res)
			if(!s.equals(str))
			System.out.println(s);
		
	}

}
