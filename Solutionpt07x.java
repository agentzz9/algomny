import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Solutionpt07x {
	private static int n;
	private static List<Integer>[] tree;

	public static int getVertexCover(int root, boolean withRoot, Map<Integer, Boolean> visited){
		int with, without;
		visited.put(root, true);
		if(isLeafNode(root)){
			return 0;
		}
		
		int numberOfChildren = noOfChildren(root);
		
		with = 1;
		for(int i=0; i<numberOfChildren; i++){
			if(!visited.get(tree[root].get(i))){
				with += getVertexCover(tree[root].get(i) , false, visited);
				visited.put(tree[root].get(i), false);
			}
		}
		
		without = numberOfChildren;
		for(int i=0; i<numberOfChildren; i++){
			if(!visited.get(tree[root].get(i))){
				without += getVertexCover(tree[root].get(i) , true, visited);
			}
		}
		

		return Integer.min(with, without);
		
	}
	private static int noOfChildren(int nodeValue) {
		
		return tree[nodeValue].size();
		
	}
	public static boolean isLeafNode(int nodeValue){
	
		if((tree[nodeValue].size()==1&&nodeValue!=1)  || tree[nodeValue].isEmpty()){
			return true;
		}
		return false;
	}
	public static void main(String[] args) {
		
		Map<Integer, Boolean> visited;
		Scanner scanner = new Scanner(System.in);
		int a, b;
		n = scanner.nextInt();
		if(n==0 /*|| n==1*/){
			System.out.println("0");
			return;
		}
		/*
		if(n==2){
			System.out.println("1");
			return;
		}*/
		tree = new ArrayList[n+1];
		
		for(int i=0; i<=n; i++){
			tree[i] = new ArrayList<Integer>();
		}
		
		visited = new HashMap<Integer, Boolean>();
		for(int i=1; i<=n-1; i++){
			a = scanner.nextInt();
			b = scanner.nextInt();
			tree[a].add(b);
			tree[b].add(a);
			visited.put(i, false);
		}
		visited.put(n, false);
		for(int i=1; i<=n; i++){
			System.out.print(i+"> ");
			System.out.println(tree[i]);
		}
		
		System.out.println(Integer.min(getVertexCover(1, true, visited), getVertexCover(1, true, visited)));

	}

}
