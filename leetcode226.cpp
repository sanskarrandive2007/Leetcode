// Q] Invert a Binary Tree ?
// Given the root of a binary tree, invert the tree, and return its root.

// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// Solution Of This Question :-

class Solution {
public:
    void invert(TreeNode* root){

        if(root == NULL) return;

        TreeNode* tmp = root -> left;
        root -> left = root -> right;
        root -> right = tmp;

        invert(root -> left);
        invert(root -> right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
        
    }
};