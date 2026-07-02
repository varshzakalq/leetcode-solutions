class Solution {
public:
    void help2(string &ans,vector<pair<int,int>> &v){
        for(int i =0;i<v.size();i++){
            ans += to_string(v[i].second);  
            ans.push_back((char)v[i].first);
        }
        return;
    }
    void help(int n,string &ans,vector<pair<int,int>>&v){
        if(n ==1){
            ans = "1";
            return;
        }
        
        for(int i = 0;i<ans.size();i++){
            int count =1;
            int temp = ans[i];
            while(i+1 <ans.size() && ans[i+1] == temp ){
                count++;
                i++;
            }
            v.push_back({temp,count});
        }
        return;
    }
    string countAndSay(int n) {
        string ans = "1";
        vector<pair<int,int>>v;
        for(int i =2;i<=n;i++){
            v.erase(v.begin(),v.end());
            help(i,ans,v);
            ans.erase(ans.begin(),ans.end());
            help2(ans,v);

        }
        return ans;

    }
};
