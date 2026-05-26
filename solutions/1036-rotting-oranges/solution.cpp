class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<int,int>> q1;
        int sec =0;
        
        for(int i =0; i<grid.size();i++){
            for(int j =0;j<grid[i].size();j++){
                if(grid[i][j]== 2){
                    q1.push({i,j});
                    
                    
            }
        }
        }
        
        
        
        while(!q1.empty()){
            
            
            
        bool rotted_any =false;
        int s= q1.size();
            for(int i =0; i<s;i++){
                pair <int,int>p = q1.front();
                q1.pop();
                //has top 
                if(p.first != 0 && grid[p.first-1][p.second] ==1){
                    grid[p.first-1][p.second] = 2;
                    q1.push({p.first-1,p.second});
                    rotted_any =true;
                    

                    
                }
                //has left element
                if(p.second != 0 && grid[p.first][p.second-1] ==1){
                    grid[p.first][p.second-1] = 2;
                    q1.push({p.first,p.second-1});

                
                    rotted_any =true;
                }
                //has bottom
                if(p.first != grid.size()-1 && grid[p.first+1][p.second] ==1){
                    grid[p.first+1][p.second] = 2;
                    q1.push({p.first+1,p.second});

                    
                    rotted_any =true;
                }
                //has right
                if(p.second != grid[p.first].size()-1 && grid[p.first][p.second+1] == 1 ){
                    grid[p.first][p.second+1] = 2;
                    q1.push({p.first,p.second+1});

                
                    rotted_any =true;
                }
                
            }
        
                if(rotted_any){
                    sec++;
                    }
                
                
        }
            
            for(int i =0; i<grid.size();i++){
                for(int j =0;j<grid[0].size();j++){
                    if(grid[i][j]== 1){
                        return -1;
                    }

                }
        }
        
        return sec;
    }
};
