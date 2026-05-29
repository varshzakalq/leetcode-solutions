class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int>prev(text1.size()+1,0);
        vector <int>curr(text1.size()+1,0);
        
        for(int i =1;i<=text2.size();i++){
            for(int j = 1; j<=text1.size();j++){
                if(text1[j-1] == text2[i-1]){
                    curr[j] = 1+prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
            vector<int>v(text1.size()+1, 0);
            curr = v;
        }
        return prev[text1.size()];
        
    }
};
