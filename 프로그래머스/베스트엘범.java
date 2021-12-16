package 프로그래머스;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

import 연습장.iterator_ex;

class tuple implements Comparable<tuple> {
	String str;
	int plays, idx;

	public tuple(String str, int plays, int idx) {
		this.idx = idx;
		this.plays = plays;
		this.str = str;
	}

	@Override
	public int compareTo(tuple o) {
		return plays - o.plays;
	}
}

public class 베스트엘범 {

	public static void main() {
		
		String[] genres = {"c","p","c","c","p"};
		int [] plays = {50,60,15,80,250};

		int[] answer = new int[100];
		List<tuple> list = new ArrayList<tuple>();

		HashMap<String, Integer> key = new HashMap<>();

		for (int x = 0; x < genres.length; x++) {

			if (key.getOrDefault(genres[x], 0) != 0) // 내용이 있으면
			{
				list.add(new tuple(genres[x],plays[x],x));
				key.put(genres[x], key.get(genres[x]) + plays[x]);
			} else // 없으면 새로
			{
				list.add(new tuple(genres[x],plays[x],x));
				key.put(genres[x], plays[x]);
			}
		}
		
		for(tuple L : list) {
			System.out.println(L.str+""+L.plays+""+L.idx);
		}
		

	}
}
