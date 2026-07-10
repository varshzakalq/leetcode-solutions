class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set <int>row;
        set <int> col;
        for (int i =0;i<matrix.size();i++){
            for(int j =0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        while(row.size()>0){
            int ele = *row.begin();
            row.erase(ele);
            fill(matrix[ele].begin(),matrix[ele].end(),0);
        }
        while(col.size()>0){
            int ele = *col.begin();
            col.erase(ele);
            for(int i = 0;i<matrix.size();i++){
                matrix[i][ele] =0;
            }
        }
        return ;
    }
};