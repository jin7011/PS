package ����;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class ��ü�� {
	
	static int n,left,right,mid;
	static int res;
	static ArrayList<pair> arr,sum;
	
	static class pair implements Comparable<pair>{
		
		int idx,dis;
		
		pair(int i,int d){
			this.idx = i;
			this.dis = d;
		}

		@Override
		public int compareTo(pair o) {
			return idx - o.idx;
		}
		
	}
	
	
	//�ٿ�� �������µ� ������ �����ϱ� �� �Ѿ�� ����
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		arr= new ArrayList<>();
		sum = new ArrayList<>();
		
		for(int x=0; x<n; x++) {
			st = new StringTokenizer(br.readLine());
			int idx = Integer.parseInt(st.nextToken());
			int dis =  Integer.parseInt(st.nextToken());
			arr.add(new pair(idx,dis));
		}
		
		arr.add(new pair(0,0));
		sum.add(new pair(0,0));
		Collections.sort(arr);
		
		for(int x=1; x<arr.size(); x++) {
			int idx = arr.get(x).idx;
			int dis = arr.get(x).dis;
			
			sum.add(new pair(idx,dis+sum.get(idx-1).dis));
		}
		
		left = 1;
		right = n;
		res = Integer.MAX_VALUE;
		
		while(left <= right) {
			
			mid = (left+right)/2;
			
			int leftsum = sum.get(mid-1).dis;
			int rightsum = sum.get(n).dis - sum.get(mid).dis;
//			int gap = Math.abs(leftsum-rightsum);
			
			if(leftsum < rightsum) {
				left = mid+1;
			}else { //���ʿ��� ������ �ִ� ����: ���������� ũ�ų� ���� ����� ���� ������ ��츦 ��� �����ð�,���� ������ �ϳ��� üũ�ϴ� �����̶�� �� 
				right = mid-1;
				res = Math.min(res, mid);
			}
			
		}
		System.out.println(res);
	}

}
