class Solution {
public:
    double bfs(string start,string target,unordered_map <string,vector<pair<string,double>>>&graph){
        if(graph.find(start) == graph.end()||graph.find(target) == graph.end()){
            return -1.0;
        }
        if(start == target)return 1.0;
        queue <pair<string,double>>q;
        unordered_set <string >visited;
        q.push({start,1.0});
        visited.insert(start);
        while(!q.empty()){
            auto[curr,curr_prod] = q.front();
            q.pop();
            if(curr == target){
                return curr_prod;
            }
            for(auto& neighbor : graph[curr]){
                string next_node = neighbor.first;
                double edge_weight = neighbor.second;
                if (visited.find(next_node) == visited.end()){
                    visited.insert(next_node);
                    q.push({next_node,curr_prod*edge_weight});
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map <string,vector<pair<string,double>>>graph;
        for(int i =0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b,val});
            graph[b].push_back({a,1.0/val});
        }
        vector <double> ans;
        for(auto i: queries){
            ans.push_back(bfs(i[0],i[1],graph));
        }
        return ans;
       

    }
};
