class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        
        while(left <= right&& top<= bottom){
            int i = left;
            while(i<=right){
                ans.push_back(matrix[top][i]);
                i++;
            }
            top++;
            i = top;
            while(i<=bottom){
                ans.push_back(matrix[i][right]);
                i++;
            }
            right--;
            i = right;
            if(top<=bottom){
                while(i>= left){
                ans.push_back(matrix[bottom][i]);
                i--;
                }
            }
            bottom--;
            i = bottom;
            if(left<= right){
                while(i >= top){
                ans.push_back(matrix[i][left]);
                i--;
            }
            }
            left++;
            
        }
        return ans;
    }
};