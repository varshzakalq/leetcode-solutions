class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map <map<char,int>,int>m1;
        int count =1;
        for(int i =0;i<strs.size();i++){
            map<char,int>temp_map;
            for(int j =0; j<strs[i].size();j++)
                temp_map[strs[i][j]] ++;
            if(m1[temp_map] != 0){
                int place = m1[temp_map]-1;
                ans[place].push_back(strs[i]);
            }
            else{
                ans.push_back({strs[i]});
                m1[temp_map] = count++;
            }
        }
        return ans;
    }
};