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
    TreeNode* getRsucc(TreeNode* root){
        if(root->left == NULL){
            return root;
        }
        return getRsucc(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return root;
        if(key == root->val){
            //0 child case
            if(root->left == NULL &&root->right == NULL){
                return NULL;
            }
            // 1 child case
            else if(root->left == NULL){
                auto temp = root->right;
                delete(root);
                return temp;

            }
            else if(root->right == NULL){
                auto temp = root->left;
                delete(root);
                return temp;
            }
            // 2 child case
            auto g = getRsucc(root->right);
            root->val = g->val;
            root->right = deleteNode(root->right, g->val);
            return root;
        }
        if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            root->left = deleteNode(root->left,key);
        }
        return root;
    
    }
};
