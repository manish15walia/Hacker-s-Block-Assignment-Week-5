import java.util.*;
public class Main {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		Main m = new Main();
		int[] pre = takeInput();
		int[] in = takeInput();
		BinaryTree bt = m.new BinaryTree(pre, in);
		bt.display();
	}

	public static int[] takeInput() {
		int n = scn.nextInt();

		int[] rv = new int[n];
		for (int i = 0; i < rv.length; i++) {
			rv[i] = scn.nextInt();
		}

		return rv;
	}

	private class BinaryTree {
		private class Node {
			int data;
			Node left;
			Node right;
		}

		private Node root;
		private int size;
		int lo=-1;

		public BinaryTree(int[] pre, int[] in) {
			this.root = this.construct(pre, 0, pre.length - 1, in, 0, in.length - 1);
		}
		public int find(int []in,int ilo,int ihi,int num){
			for(int i=ilo;i<=ihi;i++){
				if(in[i]==num){
					return i;
				}
			}
			return -1;
		}
		
       
		private Node construct(int[] pre, int plo, int phi, int[] in, int ilo, int ihi) {

			// write your code here
			if(lo==-1){
				lo=phi;
			}
			if(lo<0 || ilo>ihi){
				return null;
			}
			Node  n=new Node();
			n.data=pre[lo];
			int num=pre[lo--];
 			int index=find(in,ilo,ihi,num);
			n.right=construct(pre,lo,phi,in,index+1,ihi);
            n.left=construct(pre,lo,phi,in,ilo,index-1);
			
			return n;
		}

		public void display() {
			this.display(this.root);
		}

		private void display(Node node) {
			if (node == null) {
				return;
			}

			String str = "";

			if (node.left != null) {
				str += node.left.data;
			} else {
				str += "END";
			}

			str += " => " + node.data + " <= ";

			if (node.right != null) {
				str += node.right.data;
			} else {
				str += "END";
			}

			System.out.println(str);

			this.display(node.left);
			this.display(node.right);
		}

	}

}
