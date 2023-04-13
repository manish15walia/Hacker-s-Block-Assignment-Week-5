#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

Node* buildBST(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return nullptr;
    }
    Node* root = new Node(nums[0]);
    for (int i = 1; i < n; i++) {
        Node* curr = root;
        while (true) {
            if (nums[i] < curr->val) {
                if (curr->left == nullptr) {
                    curr->left = new Node(nums[i]);
                    curr->left->parent = curr;
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right == nullptr) {
                    curr->right = new Node(nums[i]);
                    curr->right->parent = curr;
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
    }
    return root;
}

Node* inorderSuccessor(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right) {
        // If node has a right child, its in-order successor is the leftmost child
        // in the right subtree
        Node* curr = node->right;
        while (curr->left) {
            curr = curr->left;
        }
        return curr;
    } else {
        // If node does not have a right child, its in-order successor is the first
        // parent whose left child is the node itself
        Node* curr = node;
        while (curr->parent && curr == curr->parent->right) {
            curr = curr->parent;
        }
        return curr->parent;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cin >> k;

    Node* root = buildBST(nums);

    Node* curr = root;
    while (curr && curr->val != k) {
        if (k < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    Node* succ = inorderSuccessor(curr);
    if (succ) {
        cout << succ->val << endl;
    } else {
        cout << "null" << endl;
    }

    return 0;
}
