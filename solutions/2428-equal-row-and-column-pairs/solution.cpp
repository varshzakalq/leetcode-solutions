class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<int,std::vector<int>> m1;
        set<std::vector<int>> s1;
        /*for(int i =0; i<grid.size();i++){
            m1[i]= grid[i];

        }*/
        //storing vertical vecotrs in map
        for(int i =0; i<grid.size();i++){
            vector<int> v1;
            for(int j =0;j<grid.size();j++){
                v1.push_back(grid[j][i]);
            }
            m1[i]   = v1;
        }
        int count =0;
        /*for(int i =0;i<grid.size(); i++){
            if(s1.find(m1[i]) != s1.end())count++;
        }*/
        for(int i =0; i<grid.size();i++){
            for(int j =0;j<grid.size();j++){
                if(m1[i] == grid[j])count++;
            }
        }
        return count;

    }
};
