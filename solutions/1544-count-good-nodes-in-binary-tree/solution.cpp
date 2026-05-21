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
public:
    int isgood(TreeNode* root,int h){
        if(root == NULL)return 0;
        if(root->val >= h){
            return 1+isgood(root->left,root->val)+isgood(root->right,root->val);
        }
        if(root->val <h){
            return isgood(root->left,h)+isgood(root->right,h);
        }
        return 0;
    }
    int goodNodes(TreeNode* root) {
        int h = INT_MIN;
        int n = isgood(root,h);
        return n;
    }
};
