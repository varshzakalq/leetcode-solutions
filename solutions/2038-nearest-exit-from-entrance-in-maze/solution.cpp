class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue <pair <int,int>>q1;
        pair<int,int>enter = {entrance[0],entrance[1]};
        q1.push(enter);
        maze[enter.first][enter.second] = '+';
        int steps =0;
        while(!q1.empty()){
            bool moved = false;
            bool destiny = false;
            int s = q1.size();
            if(destiny)break;
            for(int i=0; i<s;i++){
                pair <int,int>p1 = q1.front();
            
                if(p1 != enter &&(p1.first==0||p1.second ==0 ||p1.first == maze.size()-1 || p1.second == maze[p1.first].size()-1) ){return steps;}
                
                q1.pop();
                //has top
                if(p1.first != 0 &&maze[p1.first-1][p1.second] == '.'){
                    maze[p1.first-1][p1.second] = '+';
                    q1.push({p1.first-1,p1.second});
                    moved = true;
                }
                //has left
                if(p1.second != 0 &&maze[p1.first][p1.second-1] == '.'){
                    maze[p1.first][p1.second-1] = '+';
                    q1.push({p1.first,p1.second-1});
                    moved = true;
                }
                if(p1.first != maze.size() -1 &&maze[p1.first+1][p1.second] == '.'){
                    maze[p1.first+1][p1.second] = '+';
                    q1.push({p1.first+1,p1.second});
                    moved = true;
                }
                if(p1.second != maze[p1.first].size()-1&&maze[p1.first][p1.second+1] == '.'){
                    maze[p1.first][p1.second+1] = '+';
                    q1.push({p1.first,p1.second+1});
                    moved = true;
                }
            }
            if(moved)steps++;

        }
        if(steps == 0 || q1.empty())return -1;
        return steps;
            
    }
};
