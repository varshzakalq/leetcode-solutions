class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a =cost[0];
        int b = cost[1];
        if(cost.size()==1)return a;
        
        for(int i = 2;i<cost.size();i++){
            int temp =a;
            a = b;
            b = cost[i]+min(temp,b);
            
        }
        return min(a,b);
    }
};
