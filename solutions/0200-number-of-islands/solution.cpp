class Solution {
    void bfs(int i ,int j, vector<vector<char>>& grid,vector<vector<bool>>& visited){
        queue <pair<int,int> > q;
        q.push({i,j});
        visited[i][j]= true;
        while(!q.empty()){
            pair <int,int> ele = q.front();
            
            q.pop();
            if(ele.first>0&& grid[ele.first -1][ele.second] == '1' && !visited[ele.first -1][ele.second]){
                q.push({ele.first-1,ele.second});
                visited[ele.first-1][ele.second]= true;
            }
            if(ele.second>0 && grid[ele.first ][ele.second-1] == '1' && !visited[ele.first ][ele.second-1]){
                q.push({ele.first,ele.second-1});
                visited[ele.first][ele.second-1]= true;
            }
            if(ele.first<grid.size()-1&& grid[ele.first +1][ele.second] == '1' && !visited[ele.first +1][ele.second]){
                q.push({ele.first+1,ele.second});
                visited[ele.first+1][ele.second]= true;
            }
            if(ele.second<grid[ele.first].size()-1&& grid[ele.first ][ele.second+1] == '1'&& !visited[ele.first ][ele.second+1]){
                q.push({ele.first,ele.second+1});
                visited[ele.first][ele.second+1]= true;
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i =0;i<grid.size();i++){
            
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] =='1'&& !visited[i][j])
                {
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};
