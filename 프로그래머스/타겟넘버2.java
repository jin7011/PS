package ÇÁ·Î±×·¡¸Ó½º;

public class Å¸°Ù³Ñ¹ö2 {

	public static void main(String[] args) {

		int numbers[] = { 1, 1,1,1,1 };
		int target = 3;

		int answer = 0;

		answer = func(numbers, target, 0);
		
		System.out.println(answer);

	}

	public static int func(int[] num,int target,int idx) {
		
		if(idx == num.length) {
			int sum = 0;
			for(int n : num) {
				sum += n;
			}

			return target == sum ? 1:0;
		}
		
		int cnt = 0;
		
		cnt += func(num,target,idx+1); // +»óÅÂ·Î µ¡¼À
		
		num[idx] *= -1; // À½¼öÈ­½ÃÄÑÁÜ
		cnt += func(num,target,idx+1); // -»óÅÂ·Î µ¡¼À
		
		num[idx] *= -1; //¿ø»óº¹±Í
		
		return cnt;
	}
}
