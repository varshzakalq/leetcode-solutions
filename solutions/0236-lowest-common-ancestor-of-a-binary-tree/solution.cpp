/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void search(TreeNode* p , TreeNode* root,vector <struct TreeNode*> &v1,bool &found){
        if(root == NULL){
            return;
        }

        v1.push_back(root);
        if(root== p){
            found = true;
            return;
        }
        search(p,root->left,v1,found);
        search(p,root->right,v1,found);
        if(found != true)
            v1.pop_back();
        

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      vector <struct TreeNode*> v1;
      bool found =false;
      search(p,root,v1,found);
      vector <struct TreeNode*> v2;
      bool found1 = false;
      search(q,root,v2,found1);
      
      
      int i =-1;
      while(i+1<min(v1.size(),v2.size())){
        if(v1[i+1] ==v2[i+1]){
            i++;
        }
        else {
            break;
        }
      }
      return v1[i];
        
    }
};
