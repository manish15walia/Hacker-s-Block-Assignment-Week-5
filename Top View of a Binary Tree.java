import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.*;

class Main {
	static class BinaryTreeFromLvlOrder {
		private Scanner s = new Scanner(System.in);
		private class Node {
			int val;
			Node left;
			Node right;
			public Node(int val) {
				this.val = val;
			}
		}
		private Node root;
		public BinaryTreeFromLvlOrder() {
			// TODO Auto-generated constructor stub
			root = construct();// 2k
		}
		private Node construct() {
			// TODO Auto-generated method stub
			int val = s.nextInt();
			Node nn = new Node(val);
			Queue<Node> lvl = new LinkedList<>();
			lvl.add(nn);
			while (!lvl.isEmpty()) {
				Node front = lvl.remove();
				int a = s.nextInt();
				int b = s.nextInt();
				if (a != -1) {
					Node na = new Node(a);
					front.left = na;
					lvl.add(na);
				}
				if (b != -1) {
					Node nb = new Node(b);
					front.right = nb;
					lvl.add(nb);
				}
			}
			return nn;// 2k
		}
		//Write your function here
    class Pair{
        Node first;
        int second;
        Pair(Node n,int val){
            first=n;
            second=val;
        }
    }
	public  void TopView(Node root){
       TreeMap<Integer,Integer>mp=new TreeMap<>();
	   Queue<Pair>q=new LinkedList<>();
	   q.add(new Pair(root,0));
       while(!q.isEmpty()){
           int st=q.size();
           for(int i=0;i<st;i++){
               Pair p=q.poll();
               Node n=p.first;
               int idx=p.second;
               if(!mp.containsKey(idx)){
                   mp.put(idx,n.val);
               }
               if(n.left!=null){
                    q.add(new Pair(n.left,idx-1));
               }
               if(n.right!=null){ 
                   q.add(new Pair(n.right,idx+1));
               }
           }
       }
        for(int val:mp.keySet()){
            System.out.print(mp.get(val)+" ");
        }   
       }
	}
	public static void main(String[] args) {
		BinaryTreeFromLvlOrder bt = new BinaryTreeFromLvlOrder();
		bt.TopView(bt.root);		
	}
}
