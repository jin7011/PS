package ����;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class ���߿켱����ť {
	
	//d 1 �ִ밪����
	//d -1 �ּҰ� ����
	//������� �� d���� ����
	//���� �ִ밪�� �ּڰ� ��������� EMPTY���
	
	static int testcase,k;
	static char order;
	static TreeMap<Long,Integer> map = new TreeMap<>();
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		testcase = Integer.parseInt(st.nextToken());
		
		for(int x=0; x<testcase; x++) {
			
			k = Integer.parseInt(st.nextToken());
			
			for(int q=0; q<k; q++) {

				st = new StringTokenizer(br.readLine());
				order = (char)st.nextElement();
				
				if(order == 'D') {
					
				}
				
				else if(order == 'I') {
					
				}
				
			}
			
			
		}
		
	}

}
