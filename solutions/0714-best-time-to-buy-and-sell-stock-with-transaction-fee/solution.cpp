class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int profit =0;
        int curr = -prices[0];
        for(int i = 1; i<n;i++){
            int prev_hold = curr;
            curr = max(curr, profit - prices[i]);
            profit = max(profit,prev_hold+prices[i]-fee);
        }
        return profit;
        
    }
};
