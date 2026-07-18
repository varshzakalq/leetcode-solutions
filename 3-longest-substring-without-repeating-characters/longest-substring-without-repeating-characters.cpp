class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int>mp;
        int longest = 0;
        int curr=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]] ==0){
                curr++;
                mp[s[i]] = i+1;

            }
            else{
                int id = mp[s[i]];
                int prev = curr;
                curr =i-(id-1);
                for(int j =i-prev;j<id;j++){
                    mp[s[j]] =0;
                }
                mp[s[i]] = i+1;
            }
            longest =  (curr>longest)?curr:longest;
        }
        return longest;
    }
};