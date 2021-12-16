package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 택배 {

	static class tuple implements Comparable<tuple> {

		int start, end, weigh;

		tuple(int s, int e, int w) {
			this.start = s;
			this.end = e;
			this.weigh = w;
		}

		@Override
		public int compareTo(tuple o) {
			if (end == o.end) {
				return start - o.start;
			}

			return end - o.end;
		}
	}

	static PriorityQueue<tuple> pq = new PriorityQueue<tuple>();
	static int s, e, w, n, c, size, capa, des, start, res = 0;
	static int[] town;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		town = new int[n+1];
		st = new StringTokenizer(br.readLine());

		size = Integer.parseInt(st.nextToken());

		for (int x = 0; x < size; x++) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());

			pq.add(new tuple(s, e, w));
		}
		
		for(int x=1; x<=n; x++) {
			town[x] = c;
		}

		while(!pq.isEmpty()) {
			tuple t = pq.poll();
			
			int capa = Integer.MAX_VALUE;
			s = t.start;
			e = t.end;
			w = t.weigh; //상자의 무게
			
			for(int x=s; x<=e; x++) {
				capa = Math.min(capa, town[x]); // 박스의 경로중에 가장 최대무게량이 적은 마을의 무게
			}
			
			if(w <= capa) // 상자를 고스란히 가져갈 수 있다면
			{
				for(int x=s;x<e;x++) { //무게 다 빼주고
					town[x] -= w;
				}
				res+=w;
			}else {
				for(int x=s;x<e;x++) { //아니라면 최소만큼만 빼주고(들고가고)
					town[x] -= capa;
				}
				res+=capa;
			}
			

		}
		System.out.println(res);
	}
}
//
////		while(!pq.isEmpty()) {
////			tuple t = pq.poll();
////			System.out.println(t.start +" " +t.end+" "+t.weigh);
////		}
//
//		int box = 0;
//		for (int town = n; town >0; town--) { // 마을은 안들리는 곳 없이 다 들림.
//
//			if (!load.isEmpty()) { // 상자를 놓고 갈 수 있다면
//				
//				box = load.peek().start; // 놓고갈게 있는지
//				
//				while (!load.isEmpty()) {
//					int w = load.peek().weigh;
//					int cur = load.peek().start;
//
//					if (cur == town) {
//						capa -= load.poll().weigh; // 내려놓자
//						res += w; // 내려놓은 상자무게 계속 결과로 체크
//					} else {
//						break;
//					}
//				}
//			}
//
//			if (!pq.isEmpty()) { // 상자를 챙길 수 있다면,
//				////////////////////////////////////////////
//				
//				start = pq.peek().start; // 가져갈게 있는지 확인하려고
//				
//				while (true) {
//
//					if (!pq.isEmpty()) {
//						start = pq.peek().start;
//						des = pq.peek().end;
//						int weigh = pq.peek().weigh;
//
//						if (start != town || capa == c)
//							break;
//
//						if (capa < c) { // 아직 담을 수 있다면
//							int remain = weigh - (c - capa); // 담는다면
//							if (remain <= 0) {
//								pq.poll(); // 전부담아
//								load.add(new pair(des, weigh));
//								capa += weigh;
//							} else {// 일부담아
//								pq.poll();
//								load.add(new pair(des, c - capa));
//								capa += c - capa;
//							}
//						}
//					}else
//						break;
//					
//				}
//				/////////////////////////////////////////////
//			}
//			remove(town);
//		}

//		System.out.println(res);
