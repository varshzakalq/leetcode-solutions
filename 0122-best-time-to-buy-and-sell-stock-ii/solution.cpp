class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        int currmin =prices[0];
        
        int size= prices.size();
        if(size ==1)return 0;
        int i =0;
        int prof =0;
        int pur;
        while(i<size){
            if(i>=1 &&prices[i]>prices[i-1]&&i<size-1&& prices[i+1]<=prices[i]){
                prof += prices[i]- pur;
            }
            else if(i ==0 && prices[i]<prices[i+1]){
                pur = prices[i];
            }
            else if(i == size-1 &&prices[i]>prices[i-1]){
                prof += prices[i]- pur;
            }
            else if (i>=1 &&prices[i]<=prices[i-1]&&i<size-1&& prices[i+1]>prices[i]){
                pur = prices[i];
            }
            i++;
        }
        return prof;
    }
};
