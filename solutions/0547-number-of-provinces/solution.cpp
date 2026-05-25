class Solution {
public:
    void dfs(vector <vector<int>> &graph,vector<int> &vis,int node){
        vis[node] = 1;
        for(auto i = 0; i<graph[node].size();i++){
            if(i !=node && graph[node][i]==1 && !vis[i]  ){
                
                dfs(graph,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <int> vis(isConnected.size(),0);
        int count =0;
        for(auto i =0;i<vis.size();i++){
            if(vis[i] ==0){
                count++;
                dfs(isConnected,vis,i);
            }
        }
        return count;
    }
};
