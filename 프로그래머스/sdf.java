package 프로그래머스;

import java.util.HashSet;


public class sdf {
	

public void permutation(String prefix, String str, HashSet<Integer> set) {
    int n = str.length();
    
    //if (n == 0) System.out.println(prefix);
    if(!prefix.equals("")) set.add(Integer.valueOf(prefix));
    
    for (int i = 0; i < n; i++)
      permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n), set);

}

	public static void main(String[] args) {

		String str = "ABCDEFG";
		
		System.out.println(str.substring(0, 1));
	}

}


