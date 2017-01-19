import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

*/

class TestClass {
	public static void main(String args[]) throws Exception {

		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int M = s.nextInt();
		List<Integer> monkList = new ArrayList<Integer>();
		List<Integer> imonkList = new ArrayList<Integer>();

		List<Integer> monkListSorted = new ArrayList<Integer>();
		List<Integer> imonkListSorted = new ArrayList<Integer>();

		List<Integer> monkF = new ArrayList<Integer>();
		List<Integer> imonkF = new ArrayList<Integer>();

		List<Integer> monkG = new ArrayList<Integer>();
		List<Integer> imonkG = new ArrayList<Integer>();

		List<Integer> monkV = new ArrayList<Integer>();
		List<Integer> imonkV = new ArrayList<Integer>();

		int monkScore = -1;
		int imonkScore = -1;

		for (int i = 0; i < N; i++) {
			monkList.add(s.nextInt());
		}
		for (int i = 0; i < M; i++) {
			imonkList.add(s.nextInt());
		}
		monkListSorted = new ArrayList<Integer>(monkList);
		imonkListSorted = new ArrayList<Integer>(imonkList);
		Collections.sort(monkListSorted);
		Collections.sort(imonkListSorted);

		// Monk
		int sum = 0;
		for (int i = 0; i < N; i++) {

			int count = 0;
			int low = 0;
			int high = M-1;
			int mid;
			boolean found = false;
			int lastIndex = 0;
			while(low<=high){
				mid =(low+high)/2;
				lastIndex = mid;
				if(imonkListSorted.get(mid) == monkList.get(i)){
					found = true;
				
				}
				else if(imonkListSorted.get(mid) > monkList.get(i)){
					low = mid + 1;
					
				}else
				{
					high = mid - 1;
				}
			}
			
			count = M-lastIndex-1;
			
			monkF.add(count);
			monkG.add(M-count);
			
			monkV.add(monkG.get(i) * monkF.get(i));
			sum += monkV.get(i);
		}
		monkScore = sum;

		// !Monk
		sum = 0;
		for (int i = 0; i < M; i++) {

			int count = 0;
			int low = 0;
			int high = N-1;
			int mid;
			boolean found = false;
			int lastIndex = 0;
			while(low<=high){
				mid =(low+high)/2;
				lastIndex = mid;
				if(monkListSorted.get(mid) == imonkList.get(i)){
					found = true;
				
				}
				else if(monkListSorted.get(mid) > imonkList.get(i)){
					low = mid + 1;
					
				}else
				{
					high = mid - 1;
				}
			}
			
			count = N-lastIndex-1;
			
			imonkF.add(count);
			imonkG.add(N-count);
			
			imonkV.add(imonkG.get(i) * imonkF.get(i));
			sum += imonkV.get(i);
			
		}
		imonkScore = sum;

		if (monkScore == imonkScore) {
			System.out.println("Tie");

		} else {
			String out = new String();
			out = (monkScore > imonkScore) ? "Monk " + (monkScore - imonkScore) : "!Monk " + (imonkScore - monkScore);
			System.out.println(out);
		}

		/*
		 * for(int i=0; i<N; i++){ System.out.print(monkList.get(i)+" "); }
		 * System.out.println(); for(int i = 0; i<M; i++){
		 * System.out.print(imonkList.get(i)+" "); }System.out.println();
		 * for(int i=0; i<N; i++){ System.out.print(monkListSorted.get(i)+" ");
		 * } System.out.println(); for(int i = 0; i<M; i++){
		 * System.out.print(imonkListSorted.get(i)+" "); }
		 */

	}
}
