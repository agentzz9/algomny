package mypackage;

import java.util.ArrayList;
import java.util.Arrays;
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

public class Solution {

	public static int indexOfFirstLargerElement(int x, List<Integer> theSortedList) {

		int len = theSortedList.size();

		int low = 0;
		int high = len - 1;
		int mid = low;
		int idx;
		while (low <= high) {
			mid = (low + high) / 2;

			if (x >= theSortedList.get(mid)) {
			//	while (mid + 1 < len && theSortedList.get(mid + 1) == theSortedList.get(mid)) {
				//	mid++;
				//}
				idx = mid;
				low = mid+1;
			} else if (x < theSortedList.get(mid)) {
				high = mid - 1;
			} 

		}
		//System.out.println(low);
		//System.out.println(high);
		//System.out.print(mid);
		List<Integer> lis = new ArrayList<Integer>(Arrays.asList(low,mid,high));
		Collections.sort(lis);
		
		return lis.get(2);

	}

	public static void main(String args[]) throws Exception {
		/*
			System.out.println(indexOfFirstLargerElement(1, new ArrayList<Integer>(Arrays.asList(0))) == 1);
		System.out.println(indexOfFirstLargerElement(1, new ArrayList<Integer>(Arrays.asList(5))) == 0);
			System.out.println(indexOfFirstLargerElement(1, new ArrayList<Integer>(Arrays.asList(1))) == 1);
			System.out.println(indexOfFirstLargerElement(1, new ArrayList<Integer>(Arrays.asList(0, 1))) == 2);
			System.out.println(indexOfFirstLargerElement(0, new ArrayList<Integer>(Arrays.asList(0))) == 1);
		System.out.println(indexOfFirstLargerElement(0, new ArrayList<Integer>(Arrays.asList(5))) == 0);
		System.out.println(indexOfFirstLargerElement(0, new ArrayList<Integer>(Arrays.asList(1))) == 0);
		System.out.println(indexOfFirstLargerElement(0, new ArrayList<Integer>(Arrays.asList(0, 1))) == 1);
		System.out.println(indexOfFirstLargerElement(1, new ArrayList<Integer>(Arrays.asList(0, 5))) == 1);
		System.out.println(indexOfFirstLargerElement(3, new ArrayList<Integer>(Arrays.asList(0, 5))) == 1);
		System.out.println(indexOfFirstLargerElement(0, new ArrayList<Integer>(Arrays.asList(1, 3))) == 0);
		
			System.out.println(indexOfFirstLargerElement(5, new ArrayList<Integer>(Arrays.asList(1, 3))) == 2);
		
		System.out.println(indexOfFirstLargerElement(0, new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5))) == 0);
		
			System.out.println(indexOfFirstLargerElement(5, new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5))) == 5);
		
		System.out.println(indexOfFirstLargerElement(1, new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5))) == 1);
		System.out.println(indexOfFirstLargerElement(3, new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5))) == 3);
		System.out.println(indexOfFirstLargerElement(4, new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5))) == 4);
		
			System.out.println(indexOfFirstLargerElement(6, new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5))) == 5);
		
		System.out.println(indexOfFirstLargerElement(2, new ArrayList<Integer>(Arrays.asList(1, 2, 2, 4, 5))) == 3);
		
		System.exit(0);
		
		*/

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

		long monkScore = -1;
		long imonkScore = -1;
		
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
		long sum = 0;
		for (int i = 0; i < N; i++) {

			int gcount;
			int ind = indexOfFirstLargerElement(monkList.get(i), imonkListSorted);
			if(ind <=0 ){
				gcount = M;
			}else if(ind >= M){
				gcount = 0;
			}
			else{
				gcount = M - ind;
			}
			
			monkF.add(M-gcount);
			monkG.add(gcount);

			monkV.add(monkG.get(i) * monkF.get(i));
			sum += monkV.get(i);
		}
		monkScore = sum;

		// !Monk
		sum = 0;
		for (int i = 0; i < M; i++) {

			int gcount;
			int ind = indexOfFirstLargerElement(imonkList.get(i), monkListSorted);
			if(ind <=0 ){
				gcount = N;
			}else if(ind >= N){
				gcount = 0;
			}
			else{
				gcount = N - ind;
			}
			
			imonkF.add(N-gcount);
			imonkG.add(gcount);

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
