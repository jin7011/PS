package ���α׷��ӽ�;

public class Ÿ�ٳѹ�2 {

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
		
		cnt += func(num,target,idx+1); // +���·� ����
		
		num[idx] *= -1; // ����ȭ������
		cnt += func(num,target,idx+1); // -���·� ����
		
		num[idx] *= -1; //���󺹱�
		
		return cnt;
	}
}
