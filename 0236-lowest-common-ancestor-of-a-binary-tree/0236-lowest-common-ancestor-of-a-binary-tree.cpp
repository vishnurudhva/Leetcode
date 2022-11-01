/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        bool isRootLCA = (root == p || root == q);
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left != NULL && right != NULL) return root;
        
        if (isRootLCA && left || isRootLCA && right) return root;
                
        if (isRootLCA) return root;
        
        return left != NULL ? left : right;
    }
};