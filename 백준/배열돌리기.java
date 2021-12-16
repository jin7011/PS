package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 배열돌리기 {
	
	static int n,t,d;
	static int[][] map = new int[501][501];
	
	static void func_r() {
		ArrayList<Integer> main_dia = new ArrayList<>();
		ArrayList<Integer> sub_dia = new ArrayList<Integer>();
		ArrayList<Integer> Ycenter = new ArrayList<>();
		ArrayList<Integer> Xcenter = new ArrayList<>();		
		
		int idx = 0;
		
		for(int dia = 1; dia<=n; dia++) {
			main_dia.add(map[dia][dia]);
			sub_dia.add(map[dia][(n+1)-dia]);
		}
		for(int c = 1; c<=n; c++) {
			int x = (n+1)/2;
			int y = x;
			
			Ycenter.add(map[c][y]);
			Xcenter.add(map[x][c]);
			
			map[x][c] = sub_dia.get( (sub_dia.size()-1) - idx); 
			map[c][y] = main_dia.get(idx);
			
			idx++;
		}
		
		idx = 0;
		
		for (int dia = 1; dia <= n; dia++) {
			map[dia][dia] = Xcenter.get(idx);
			map[dia][(n + 1) - dia] = Ycenter.get(idx);
			idx++;
		}

	}
	
	static void func_l() {
		ArrayList<Integer> main_dia = new ArrayList<>();
		ArrayList<Integer> sub_dia = new ArrayList<Integer>();
		ArrayList<Integer> Ycenter = new ArrayList<>();
		ArrayList<Integer> Xcenter = new ArrayList<>();		

		int idx = 0;

		for (int dia = 1; dia <= n; dia++) {
			main_dia.add(map[dia][dia]);
			sub_dia.add(map[dia][(n + 1) - dia]);
		}
		
		for(int c = 1; c<=n; c++) {
			int x = (n+1)/2;
			int y = x;
			
			Ycenter.add(map[c][y]);
			Xcenter.add(map[x][c]);
			
			map[x][c] = main_dia.get(idx);
			map[c][y] = sub_dia.get(idx); 
			
			idx++;
		}

		idx = 0;

		for (int dia = 1; dia <= n; dia++) {
			map[dia][dia] = Ycenter.get(idx);
			map[dia][(n + 1) - dia] =Xcenter.get((Xcenter.size()-1) - idx); 
			idx++;
		}
		

	}

	static void show() {
		for(int y = 1; y<=n; y++) {
			for(int x=1; x<=n; x++) {
				System.out.print(map[y][x]+" ");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		t = Integer.parseInt(st.nextToken());
		
		for(int q = 0; q<t; q++) {
			
			st = new StringTokenizer(br.readLine());
			
			n = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			
			for(int y = 1; y<=n; y++) {
				st = new StringTokenizer(br.readLine());
				for(int x=1; x<=n; x++) {
					map[y][x] = Integer.parseInt(st.nextToken());
				}
			}
			
			if(d>=0) {
				d /= 45;
				for(int x=0; x<d; x++) {
					func_r();
				}
			}else {
				d = Math.abs(d);
				d /= 45;
				for(int x=0; x<d; x++) {
					func_l();
				}
			}
			
			show();
			
			
		}
	}

}
