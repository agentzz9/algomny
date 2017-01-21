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

	public static int gCount(int x, List<Integer> theSortedList) {

		int len = theSortedList.size();

		int low = 0;
		int high = len - 1;
		int mid = -1;
		int idx = -1;
		while (low <= high) {
			mid = (low + high) / 2;

			if (x >= theSortedList.get(mid)) {
			
				idx = mid;
				low = mid+1;
			} else if (x < theSortedList.get(mid)) {
				high = mid - 1;
			} 

		}

		return len -idx -1;
		
	}

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

			int gcount = gCount(monkList.get(i), imonkListSorted);
			
			monkF.add(M-gcount);
			monkG.add(gcount);

			monkV.add(monkG.get(i) * monkF.get(i));
			sum += monkV.get(i);
		}
		monkScore = sum;

		// !Monk
		sum = 0;
		for (int i = 0; i < M; i++) {

			int gcount = gCount(imonkList.get(i), monkListSorted);
			
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
