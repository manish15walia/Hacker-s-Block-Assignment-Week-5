import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static Node buildTree() {
        Node root = null;
        
        int value = sc.nextInt();
        if (value != -1) {
            root = new Node(value);
            boolean hasLeft = sc.nextBoolean();
            if (hasLeft) {
                root.left = buildTree();
            }
            boolean hasRight = sc.nextBoolean();
            if (hasRight) {
                root.right = buildTree();
            }
        }
        return root;
    }

    public static void inorder(Node root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        System.out.println(root.data + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        Node root = buildTree();
        inorder(root);
    }
}
