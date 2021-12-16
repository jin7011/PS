package ���α׷��ӽ�;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

import ������.iterator_ex;

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

public class ����Ʈ���� {

	public static void main() {
		
		String[] genres = {"c","p","c","c","p"};
		int [] plays = {50,60,15,80,250};

		int[] answer = new int[100];
		List<tuple> list = new ArrayList<tuple>();

		HashMap<String, Integer> key = new HashMap<>();

		for (int x = 0; x < genres.length; x++) {

			if (key.getOrDefault(genres[x], 0) != 0) // ������ ������
			{
				list.add(new tuple(genres[x],plays[x],x));
				key.put(genres[x], key.get(genres[x]) + plays[x]);
			} else // ������ ����
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
