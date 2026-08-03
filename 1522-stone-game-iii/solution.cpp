class Solution {
    int bestchance(vector<int>& stoneValues,int st,int end,vector<int>&dp){
        if(st>end){
            return 0;
        }
        if(st== end){
          return stoneValues[st];
        }
        if(dp[st] != -1){
            return dp[st];
          }
          int s1 = stoneValues[st] - bestchance(stoneValues,st+1,end,dp);
          int s2 = stoneValues[st] +stoneValues[st+1] - bestchance(stoneValues,st+2,end,dp);
          int s3 =(st+2<= end)? stoneValues[st] +stoneValues[st+1]+stoneValues[st+2] - bestchance(stoneValues,st+3,end,dp):INT_MIN;
          dp[st] = max(s1,max(s2,s3));
          return max(s1,max(s2,s3));

    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size(),-1);
        int net = bestchance(stoneValue,0,stoneValue.size()-1,dp);
        if(net ==0)return "Tie";
        if(net >0)return "Alice";
        return "Bob";
    }
};
