class Solution {
    int grsum(vector<int>& piles,int st, int end,vector<vector<int>>&dp){
        if(st == end){
            return piles[st];
        }
        if(dp[st][end] != -1){
            return dp[st][end];
        }
        int leftchoice = piles[st]-grsum(piles,st+1,end,dp);
        int rightchoice = piles[end]-grsum(piles,st,end-1,dp);
        dp[st][end] = (leftchoice>=rightchoice)? leftchoice:rightchoice;
        return (leftchoice>=rightchoice)? leftchoice:rightchoice;
        
    }
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
