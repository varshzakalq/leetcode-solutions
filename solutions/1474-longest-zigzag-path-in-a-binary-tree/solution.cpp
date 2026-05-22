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
    int ml (TreeNode* root,int d){
        int l = 0;
        while(root != NULL){
            //1 = left 
            if(d == 1){
                root = root->left;
                d=0;
                l++;
            }
            else{
                root= root->right;
                d=1;
                l++;
            }
        }
        return l;
    }
    
    int longestZigZag(TreeNode* root) {
        if(root == NULL)return 0;
        int l1 = ml(root,1);
        int l2 = ml(root,0);
        int a = max(l1,l2)-1;
        return max(max(longestZigZag(root->left),longestZigZag(root->right)),a);
        
    }
};
