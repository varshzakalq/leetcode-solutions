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
    int height(TreeNode* root){
        if(root== NULL)return -1;
        else{
            return 1+max(height(root->left),height(root->right));
    }
    }
    void getlevel(int h,TreeNode* root,int &rv){
        if(root ==NULL)return;
        if(h==0){
            rv = root->val;
            return;
        }
        if(h>0){
            getlevel(h-1,root->left,rv);
            getlevel(h-1,root->right,rv);
        }
    }
    void lot (TreeNode* root,vector<int> &v1){
        int hei = height(root);
        if(hei == -1)return;

        for(int i =0; i<=hei  ;i++){
            int rightmost_val;
            getlevel(i,root,rightmost_val);
            v1.push_back(rightmost_val);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector <int> v1;
        lot(root,v1);
        return v1;
    }
};
