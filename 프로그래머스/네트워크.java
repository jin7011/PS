package 프로그래머스;

import java.util.LinkedList;
import java.util.Queue;

public class 네트워크 {
	public static void main(String[] args) {
		int n;
		int[][] computers = {{1, 1, 0,1,0,1}, {1, 1, 0,1,0,1}, {0, 0, 1,0,1,0},{0,1,0,1,0,1},{0,0,1,0,1,0},{0,0,0,1,0,1}};
		int answer = 0;
		
		Queue<Integer> que = new LinkedList<>();
		boolean[] visited = new boolean[computers.length];
		
		for(int y=0; y<computers.length; y++) {
			
			if(visited[y]) continue;
			
			que.add(y);
			visited[y] = true;
			
			while(!que.isEmpty()) {
				
				int qf = que.poll();
				
				for(int x=0; x<computers[qf].length; x++) {
					if(!visited[x] && computers[qf][x] != 0 && qf!=x) {
						visited[x] = true;
						que.add(x);
					
					}
				}
			}
			answer++;
		}
		System.out.println(answer);
	}
}
