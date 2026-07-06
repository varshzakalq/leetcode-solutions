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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int st_idx,int end_idx){
        if(st_idx>end_idx)return NULL;
        int i =0;
        int index =0 ;
        for(int j =postorder.size()-1;j>=0;j--){
            i = static_cast<int>(find(inorder.begin()+st_idx,inorder.begin()+end_idx+1, postorder[j])-inorder.begin());
            if(i !=end_idx+1 ){//what about +1
                index =j;
                break;
            }
        }
        TreeNode* root = new TreeNode(postorder[index]);
        postorder.erase(postorder.begin()+index);
        root->right =build(inorder,postorder,i+1,end_idx);
        root->left = build(inorder,postorder,st_idx,i-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)return NULL;
        TreeNode* root = build(inorder,postorder,0,inorder.size()-1);
        return root;
    }
};