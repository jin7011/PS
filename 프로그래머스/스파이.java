package ���α׷��ӽ�;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class ������ {

	public static void main(String[][] args) {
		
		int answer = 0;
		
		HashMap<String, Integer> map = new HashMap<String,Integer>();
		
		for(int y=0; y<args.length; y++) { // ���� ������ �˸��
			map.put(args[y][1], map.getOrDefault(args[y][1], 0) +1);
		}
		
		Set <Map.Entry<String,Integer>> s = map.entrySet();
		
		for(Map.Entry<String, Integer> e : s) {
			answer*= e.getValue();
		}
	}
}
