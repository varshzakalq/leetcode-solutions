class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int s = rooms.size();
        vector <int> vis(s,0);
        queue <int > q1;
        q1.push(0);
        vis[0] = 1;
        while(!q1.empty()){
            int top =q1.front();
            q1.pop();
            for(auto i: rooms[top]){
                if(!vis[i]){
                    q1.push(i);
                    vis[i] =1;
                }
            }
        }
        for(auto i : vis){
            if( i == 0)return false;
        }
        return true;
    }
};
