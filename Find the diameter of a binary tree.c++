#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int diameter(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
   int o1 = diameter(root->left);
   int o2 = diameter(root->right);
   int o3 = height(root->left) + height(root->right);
   
   int result = max(o1 , max(o2,o3));
   
   return result;
}

TreeNode* createTree() {
    int val;
    cin >> val;
    if (val == -1) {
        return NULL;
    }
    TreeNode* root = new TreeNode(val);
    root->left = createTree();
    root->right = createTree();
    return root;
}

int main() {
    TreeNode* root = createTree();
    cout <<diameter(root) << endl;
    return 0;
}
