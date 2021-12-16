package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 배_1092_엄청엄청중요하다 {

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
//        ArrayList<Integer> craneList = new ArrayList<>(); // 크레인 중량
//        ArrayList<Integer> boxList = new ArrayList<>(); // 박스 무게
//        //1. 입력
//        int n = sc.nextInt(); //크레인 갯수
//        for(int i = 0; i < n; i++) {
//            int a = sc.nextInt();
//            craneList.add(a);
//        }
//        int m = sc.nextInt();//박스 갯수
//        for(int i = 0; i < m; i++) {
//            int a = sc.nextInt();
//            boxList.add(a);
//        }
//        //2. 내림차순 정렬
//        Descending descending = new Descending();
//        Collections.sort(craneList, descending);
//        Collections.sort(boxList, descending);
//        
//        int time = 0;//걸린 시간
//        //3. 가장 무거운 박스의 무게 > 크레인 최대 중량일 경우
//        if(boxList.get(0) > craneList.get(0))
//            System.out.println("-1");
//        //4. 그 외의 경우, 그리디 알고리즘
//        else{
//        	
//        	
//        	
//            while(boxList.size() != 0){ //박스를 다 옮길때까지 반복
//            	
//                int CraneIdx = 0;
//                int BoxIdx = 0;
//                
//                while(CraneIdx < n){ //크레인을 끝까지 다 체크함
//                	
//                	if(BoxIdx == boxList.size()) //박스 끝까지 다 옮김
//                        break;
//                	
//                	int boxWeight = boxList.get(BoxIdx);
//                	int CranePower = craneList.get(CraneIdx);
//                    
//                    if(boxWeight<= CranePower){
//                        boxList.remove(BoxIdx); //옮긴 박스는 치움(삭제)
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