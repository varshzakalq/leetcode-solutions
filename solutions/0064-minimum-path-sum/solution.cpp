class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        
        for(int i =1;i<grid.size();i++){
            grid[i][0] =grid[i][0]+grid[i-1][0];
            
        }
        
        for(int i =1;i<grid[0].size();i++){
            grid[0][i]+= grid[0][i-1];
            
        }
        
        
        for(int j = 1;j<grid.size();j++){
            for(int i =1;i<grid[j].size();i++){
                grid[j][i] += min(grid[j][i-1],grid[j-1][i]);
            }
            
        }
        

        return grid[grid.size()-1][grid[0].size()-1];
    }
};
