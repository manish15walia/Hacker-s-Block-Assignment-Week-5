#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
        return NULL;
    }
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = NULL;

    // Reading the input
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int p_val, q_val;
    cin >> p_val >> q_val;

    // Finding the LCA
    TreeNode* p = new TreeNode(p_val);
    TreeNode* q = new TreeNode(q_val);
    TreeNode* lca = lowestCommonAncestor(root, p, q);

    // Printing the LCA value
    cout << lca->val << endl;

    return 0;
}
