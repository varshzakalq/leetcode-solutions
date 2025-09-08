class Solution {
public:
    bool isp(string &part){
        int i= 0;
        int j= part.length() -1;
        while (i<j){
            if(part[i]==part[j]){
                i++;j--;
            
            } else {
                return false;
            }
        }
        return true;
    }
    void helper(vector<vector<string>> &ans,
        vector<string> &parti, string s){
        if(s.size()==0){
            ans.push_back(parti);
            return;
        }
        for(int i= 0; i<s.length(); i++){
            string part = s.substr(0,i+1);
            if(isp(part)){
            parti.push_back(part);
                helper(ans,parti,s.substr(i+1));
                parti.pop_back();
            }
        }
        }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parti;
        helper(ans, parti , s);
        return ans;
        
    }
};
