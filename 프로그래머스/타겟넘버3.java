package ���α׷��ӽ�;

public class Ÿ�ٳѹ�3 {

	public static void main(String[] args) {
		int numbers[] = { 1,2,3 };
		int target = 0;

		int answer = 0;

		answer = func(numbers, target, 0, 0);
		
		//System.out.println(answer);
	}
	
	public static int func(int[] num,int target,int idx, int res) {
		
		if(idx == num.length) {		
			return res == target ? 1:0;
		}
		
		return func(num,target,idx+1, res + num[idx]) + func(num,target,idx+1,res - num[idx]);
	}

}
