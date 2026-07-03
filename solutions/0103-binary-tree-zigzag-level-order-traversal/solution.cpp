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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> v;
        queue <TreeNode*> q;
        int count  =0;
        if(root ==NULL)return v;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> q2;
            v.push_back({});
            while(!q.empty()){
                TreeNode* front = q.front();
                v[count].push_back(front->val);
                if(front->left != NULL)
                    q2.push(front->left);
                if(front->right != NULL)
                    q2.push(front->right);
                q.pop();
            }
            count++;
            q = q2;
        }
        for(int i = 1 ;i<v.size();i++){
            reverse(v[i].begin(),v[i].end());
            i++;
        }
        return  v;
    }
};
