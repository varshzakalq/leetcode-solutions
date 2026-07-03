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
    void iot(TreeNode* root,vector<int> &v){
        if(root == NULL)return;
        iot(root->left,v);
        v.push_back(root->val);
        iot(root->right,v);
    }
public:

    bool isValidBST(TreeNode* root) {
        vector<int> v;
        iot(root,v);
        if (v.size()==1)return true;
        for(int i =1; i<v.size();i++){
            if(v[i-1] <v[i]);
            else return false;
        }
        return true;
    }
};
