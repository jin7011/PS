package 프로그래머스;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class 스파이 {

	public static void main(String[][] args) {
		
		int answer = 0;
		
		HashMap<String, Integer> map = new HashMap<String,Integer>();
		
		for(int y=0; y<args.length; y++) { // 옷의 종류만 알면댐
			map.put(args[y][1], map.getOrDefault(args[y][1], 0) +1);
		}
		
		Set <Map.Entry<String,Integer>> s = map.entrySet();
		
		for(Map.Entry<String, Integer> e : s) {
			answer*= e.getValue();
		}
	}
}
