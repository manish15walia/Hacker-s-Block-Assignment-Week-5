
import java.util.*;

class Main {
	static class BinaryTreeFromLvlOrder {
        static ArrayList<Integer> a = new ArrayList<>();
		 Scanner s = new Scanner(System.in);

		 class Node {
			int val;
			Node left;
			Node right;

			public Node(int val) {
				this.val = val;
			}
		}

		 Node root;

		public BinaryTreeFromLvlOrder() {
			// TODO Auto-generated constructor stub
			root = construct();// 2k
		}

		public Node construct() {
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

        void solve(Node root,int count){
            if(root==null)return;

            if(a.size()==count){
                System.out.print(root.val+" ");
                a.add(root.val);
            }
            solve(root.right,count+1);
            solve(root.left,count+1);
        }

		
		
	}

	public static void main(String[] args) {
		BinaryTreeFromLvlOrder bt = new BinaryTreeFromLvlOrder();
		bt.solve(bt.root,0);
	}
}
