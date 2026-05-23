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
        if(root == NULL)return -1;
        return 1+max(height(root->left),height(root->right));
    }
    void get_l_sum(int h,int &sum, TreeNode*r){
        if(r== NULL)return;
        if(h == 0)sum+= r->val;
        if(h>0){
            get_l_sum(h-1,sum,r->left);
            get_l_sum(h-1,sum,r->right);
        }
    }
    void lot(TreeNode* root,vector <int> &v1 ){
        int h = height(root);
        if(h ==-1)return;
        for(int i =0; i<=h; i++){
            int sum =0;
            get_l_sum(i,sum,root);
            v1.push_back(sum);
        }
    }
    int maxLevelSum(TreeNode* root) {
        vector<int>v1;
        lot(root,v1);
        int max =v1[0];
        int id =0;
        for(int i =1;i<v1.size();i++){
            if(max<v1[i]){id =i; max = v1[i];}
            
        }
        return id+1;

    }
};
