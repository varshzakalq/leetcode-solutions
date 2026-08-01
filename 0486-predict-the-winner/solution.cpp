class Solution {
    int greatest(vector<int>& nums,int left, int right ,vector<vector<int>>&dp){
        if(left == right){
            return nums[left];
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int leftchoice = nums[left]-greatest(nums,left+1,right,dp);
        int rightchoice = nums[right]-greatest(nums,left,right-1,dp);
        dp[left][right] = max(leftchoice,rightchoice);
        return dp[left][right];
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        
        int score = greatest(nums,0,nums.size()-1,dp);
        return score>=0;
    }
};
