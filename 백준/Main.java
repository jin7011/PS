package น้มุ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static ArrayList<PostInfo> postList = new ArrayList<>();
	static ArrayList<PostInfo> temp = new ArrayList<>();
	static class PostInfo{
		int good;
		
		public PostInfo(int s) {
			this.good  = s;
		}
		
		public PostInfo(PostInfo p) {
			this.good = p.get();
		}
		
		public void set(int s) {
			this.good = s;
		}
		
		public int get() {
			return this.good;
		}
	}


	public static void main(String args[]) {
		
		postList.add(new PostInfo(0));
		postList.add(new PostInfo(0));
		postList.add(new PostInfo(0));
		postList.add(new PostInfo(0));
		postList.add(new PostInfo(0));
		postList.add(new PostInfo(0));
		
		
//		for(int x=0; x<postList.size(); x++) {
//			temp.add(new PostInfo(postList.get(x)));
//		}
//		
//		temp.get(0).set(temp.get(0).get() + 1);
//		
//
//		for(PostInfo p : postList) {
//			System.out.println(p.get());
//		}
//		
//		System.out.println("-------------------");
//		
//		for(PostInfo p : temp) {
//			System.out.println(p.get());
//		}
//		
//		System.out.println(temp.get(0));
		
		Date date = new Date();
		String str = "asd";
		
		System.out.println(str+date.getTime());
		
	}
	
	}
		
