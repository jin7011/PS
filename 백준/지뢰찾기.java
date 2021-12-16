package ¹éÁØ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Áö·ÚÃ£±â {
	
	static char[][] map = new char[10][10];
	static char[][] midmap = new char[10][10];
	static char[][] resmap = new char[10][10];
	static int n;
	static boolean[][] visited = new boolean[10][10];
	static boolean flag;
	
	static ArrayList<pair> mine = new ArrayList<>();
	static Queue<pair> que = new LinkedList<>();
	static int[][] go = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,-1},{-1,1},{1,1} };
	
	static class pair{
		int y, x;
		
		pair(int y,int x){
			this.x = x;
			this.y = y;
		}
	}
	
	static boolean isrange(int y,int x) {
		return x>=0 && x<n && y>=0 && y<n;
	}
	
	static void show() {
		
		if(flag) //Áö·Ú¸¦ ¹â¾Ò´Ù¸é Áö·Ú ÀüºÎ Ç¥½Ã
		{
			for(int x=0; x<mine.size(); x++) {
				int dx = mine.get(x).x;
				int dy = mine.get(x).y;
				
				resmap[dy][dx] = '*'; 
			}
		}
	
		for(int y=0; y<n; y++) {
			for(int x=0; x<n; x++) {
				System.out.print(resmap[y][x]);
			}
			System.out.println();
		}

	}
	
	static void bfs(int y,int x) {
		
		int sum = 0;
		
		for(int q=0; q<8; q++) {
			
			int dy =  y + go[q][0];
			int dx = x + go[q][1];
			
			if(isrange(dy,dx)) {
				if(map[dy][dx] == '*')
					sum++;
			}
			
		}
		
		resmap[y][x] = Character.forDigit(sum, 10);
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		
		for(int y=0; y<n; y++) {
			String str =br.readLine();
			for(int x=0; x<n; x++) {
				char next = str.charAt(x);
				if(next == '*')
					mine.add(new pair(y,x));
				map[y][x] = next;
			}
		}
		
		for(int y=0; y<n; y++) {
			String str =br.readLine();
			for(int x=0; x<n; x++) {
				midmap[y][x] = str.charAt(x);
				resmap[y][x] = '.';
			}
		}

		for(int y=0; y<n; y++) {
			for(int x=0; x<n; x++) {
				
				if(midmap[y][x] == 'x') {
					if(map[y][x] == '*')
						flag = true;
					
					bfs(y,x);
				}
				
			}
		}
		
		show();
		
	}

}
