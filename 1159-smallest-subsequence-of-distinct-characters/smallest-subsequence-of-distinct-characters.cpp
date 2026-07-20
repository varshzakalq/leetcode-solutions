class Solution {
public:
  string smallestSubsequence(string s) {
        vector<int> last_idx(26, 0);
        vector<bool> visited(26, false);
        string ans = "";

        for(int i =0 ;i<s.length();i++){
            last_idx[s[i]-'a'] =i; 
        }
        for(int i = 0; i<s.length();i++){
            char c = s[i];
            if(visited[c-'a'])continue;
            while(!ans.empty() && ans.back()>c&&last_idx[ans.back()-'a']>i){
                visited[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            visited[c-'a'] =true;
        }

        return ans;
    }
};