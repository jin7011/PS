package ����;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class �ù� {

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
			w = t.weigh; //������ ����
			
			for(int x=s; x<=e; x++) {
				capa = Math.min(capa, town[x]); // �ڽ��� ����߿� ���� �ִ빫�Է��� ���� ������ ����
			}
			
			if(w <= capa) // ���ڸ� ������ ������ �� �ִٸ�
			{
				for(int x=s;x<e;x++) { //���� �� ���ְ�
					town[x] -= w;
				}
				res+=w;
			}else {
				for(int x=s;x<e;x++) { //�ƴ϶�� �ּҸ�ŭ�� ���ְ�(�����)
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
//		for (int town = n; town >0; town--) { // ������ �ȵ鸮�� �� ���� �� �鸲.
//
//			if (!load.isEmpty()) { // ���ڸ� ���� �� �� �ִٸ�
//				
//				box = load.peek().start; // ������ �ִ���
//				
//				while (!load.isEmpty()) {
//					int w = load.peek().weigh;
//					int cur = load.peek().start;
//
//					if (cur == town) {
//						capa -= load.poll().weigh; // ��������
//						res += w; // �������� ���ڹ��� ��� ����� üũ
//					} else {
//						break;
//					}
//				}
//			}
//
//			if (!pq.isEmpty()) { // ���ڸ� ì�� �� �ִٸ�,
//				////////////////////////////////////////////
//				
//				start = pq.peek().start; // �������� �ִ��� Ȯ���Ϸ���
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
//						if (capa < c) { // ���� ���� �� �ִٸ�
//							int remain = weigh - (c - capa); // ��´ٸ�
//							if (remain <= 0) {
//								pq.poll(); // ���δ��
//								load.add(new pair(des, weigh));
//								capa += weigh;
//							} else {// �Ϻδ��
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
