/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int height(TreeNode* root,bool &val){
        if(root == NULL){
            return 0;
        }
        int h1 = height(root->left,val);
        int h2 = height(root->right,val);
        if(abs(h1-h2)>1){
            val = false;
        }
        return max(h1,h2)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool val = true;
        height(root,val);
        return val;
    }
};
