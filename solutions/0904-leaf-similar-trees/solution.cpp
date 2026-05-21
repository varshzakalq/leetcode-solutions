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
    void ls(vector<int>&v1,TreeNode* r){
        if(r->left == NULL&& r->right ==NULL){
            v1.push_back(r->val);
            
        }
        if(r->left != NULL){
            ls(v1,r->left);
        }
        if(r->right != NULL){
            ls(v1,r->right);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector <int>v2;
        ls(v1, root1);
        ls(v2, root2);
        for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;
    for (int x : v2) {
        cout << x << " ";
    }
    cout << endl;
        return (v1==v2);
    }
};
