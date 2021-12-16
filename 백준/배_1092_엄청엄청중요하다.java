package ����;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class ��_1092_��û��û�߿��ϴ� {

	static int cranesize, boxsize, craneIdx, boxIdx, res;
	static ArrayList<Integer> crane = new ArrayList<>(), box = new ArrayList<>();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		cranesize = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int x = 0; x < cranesize; x++) {
			int weigh = Integer.parseInt(st.nextToken());
			crane.add(weigh);
		}

		st = new StringTokenizer(br.readLine());
		boxsize = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int x = 0; x < boxsize; x++) {
			int weigh = Integer.parseInt(st.nextToken());
			box.add(weigh);
		}

		Collections.sort(box,Comparator.reverseOrder());
		Collections.sort(crane,Comparator.reverseOrder());

		if (crane.get(0) < box.get(0)) {
			System.out.println(-1);
			return;
		}

		while (box.size() != 0) {

			craneIdx = 0;
			boxIdx = 0;

			while (craneIdx < crane.size()) {

				if (boxIdx >= box.size())
					break;

				int boxWeigh = box.get(boxIdx);
				int cranePower = crane.get(craneIdx);

				if (cranePower >= boxWeigh) {
					craneIdx++;
					box.remove(boxIdx);
				} else {
					boxIdx++;
				}
			}
			res++;
		}
		
		System.out.println(res);

	}
}
//        Scanner sc = new Scanner(System.in);
//        ArrayList<Integer> craneList = new ArrayList<>(); // ũ���� �߷�
//        ArrayList<Integer> boxList = new ArrayList<>(); // �ڽ� ����
//        //1. �Է�
//        int n = sc.nextInt(); //ũ���� ����
//        for(int i = 0; i < n; i++) {
//            int a = sc.nextInt();
//            craneList.add(a);
//        }
//        int m = sc.nextInt();//�ڽ� ����
//        for(int i = 0; i < m; i++) {
//            int a = sc.nextInt();
//            boxList.add(a);
//        }
//        //2. �������� ����
//        Descending descending = new Descending();
//        Collections.sort(craneList, descending);
//        Collections.sort(boxList, descending);
//        
//        int time = 0;//�ɸ� �ð�
//        //3. ���� ���ſ� �ڽ��� ���� > ũ���� �ִ� �߷��� ���
//        if(boxList.get(0) > craneList.get(0))
//            System.out.println("-1");
//        //4. �� ���� ���, �׸��� �˰���
//        else{
//        	
//        	
//        	
//            while(boxList.size() != 0){ //�ڽ��� �� �ű涧���� �ݺ�
//            	
//                int CraneIdx = 0;
//                int BoxIdx = 0;
//                
//                while(CraneIdx < n){ //ũ������ ������ �� üũ��
//                	
//                	if(BoxIdx == boxList.size()) //�ڽ� ������ �� �ű�
//                        break;
//                	
//                	int boxWeight = boxList.get(BoxIdx);
//                	int CranePower = craneList.get(CraneIdx);
//                    
//                    if(boxWeight<= CranePower){
//                        boxList.remove(BoxIdx); //�ű� �ڽ��� ġ��(����)
//                        CraneIdx++;
//                    }
//                    else if(boxWeight > CranePower){
//                    	BoxIdx++;
//                    }
//                }
//                
//                time++;
//            }
//            System.out.println(time);
//            
//            
//            
//        }
//        sc.close();
//    }
//}
//
//class Descending implements Comparator<Integer> {
// @Override
// public int compare(Integer o1, Integer o2) {
//     return o2.compareTo(o1);
// }
//}