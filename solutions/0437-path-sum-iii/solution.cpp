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
    int ps(TreeNode* root,int targetSum,unordered_map<double,int> prefixCount,double cs){
        if(root == NULL){
            return 0;
        }
        cs+=root->val;
        int result =0; 
        if (prefixCount.count(cs - targetSum)) {
            result += prefixCount[cs - targetSum];
        }
        prefixCount[cs]++;
        result += ps(root->left, targetSum, prefixCount, cs);
        result += ps(root->right, targetSum, prefixCount, cs);

        // backtrack
        prefixCount[cs]--;

        return result;

    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<double,int> prefixCount;
        prefixCount[0] =1;
        int n = ps(root,targetSum,prefixCount,0);
        return n;

         
    }
};
