class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj,vector <int>&vis,int &count ,int node){
        vis[node] = 1;
        for(int i =0; i<adj[node].size();i++){
            if(!(vis[adj[node][i].first])){
                if(adj[node][i].second == 1)count ++;
                dfs(adj,vis,count,adj[node][i].first);
            }
            
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
      vector<vector<pair<int,int>>> adj(n);
      for(int i =0; i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
      }
      int count = 0;
      vector<int> vis(n,0);
      dfs(adj,vis,count,0);
      return count;
    }
};
