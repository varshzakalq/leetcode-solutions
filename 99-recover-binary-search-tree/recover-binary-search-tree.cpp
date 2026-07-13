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
    void iot(TreeNode* root,vector<TreeNode*> &list){
        if(root == NULL){
            return;
        }
        
        iot(root->left,list);
        list.push_back(root);
        iot(root->right,list);
        
        return;
    }
    void recoverTree(TreeNode* root) {
        vector <TreeNode*> list;
        iot(root,list);
        TreeNode* prev = list[0];
        TreeNode* t1= NULL;
        TreeNode* t2 = NULL;
        for(int i = 1;i<list.size();i++){
            if(prev->val > list[i]->val && t1 == NULL){
                t1 = prev;
                t2 = list[i];
            }
            else if(prev->val >list[i]->val){
                t2 = list[i];
            }
            prev = list[i];
        }
        int t  = t2->val;
        t2->val = t1->val;
        t1->val = t;

    }
};