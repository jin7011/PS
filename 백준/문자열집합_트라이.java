package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class 문자열집합_트라이 {

	static int n, m;
	static Set<String> set = new HashSet<>();

	static class trieNode {

		private HashMap<Character, trieNode> childNode = new HashMap<>();
		private boolean isLast;

		public HashMap<Character, trieNode> getChild() {
			return this.childNode;
		}

		public void setisLast(boolean s) {
			this.isLast = s;
		}

		public boolean getisLast() {
			return this.isLast;
		}

	}

	static class trie {

		trieNode root;

		trie() {
			root = new trieNode();
		}

		public void insert(String str) {

			trieNode current = this.root;

			for (int x = 0; x < str.length(); x++) {
				HashMap<Character, trieNode> child = current.getChild();

				if (!child.containsKey(str.charAt(x))) {
					child.put(str.charAt(x), new trieNode());
					current = child.get(str.charAt(x));
				} else
					current = child.get(str.charAt(x));
			}

			current.setisLast(true);
		}

		public boolean contain(String str) {

			trieNode current = this.root;

			for (int x = 0; x < str.length(); x++) {
				HashMap<Character, trieNode> child = current.getChild();

				if (!child.containsKey(str.charAt(x))) {
					return false;
				} else
					current = child.get(str.charAt(x));
			}

			if (current.isLast)
				return true;
			else
				return false;

		}
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
//		trie t = new trie();
//
		for (int x = 0; x < n; x++) {
			String str = br.readLine();
			set.add(str);
			
		}
//			t.insert(str);
//		}
//
		int res = 0;
//
		for (int x = 0; x < m; x++) {
			String str = br.readLine();
			if(set.contains(str)) res++; }
//			if (t.contain(str))
//				res++;
//		}
		
		

		System.out.println(res);
	}

}
