class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>p1;
        priority_queue<int,vector<int>,greater<int>>p2;
        int left = 0;
        int right = costs.size()-1;
        long long cost  = 0;
        while(k>0){
            while(p1.size()<candidates &&left <= right){
                p1.push(costs[left++]);
            }
            while(p2.size()<candidates &&left <= right){
                p2.push(costs[right--]);
            }
            int t1= (!p1.empty())?p1.top():INT_MAX;
            int t2 = (!p2.empty())?p2.top():INT_MAX;
            if(t2<t1){
                cost += t2;
                p2.pop();
            }
            else{
                cost += t1;
                p1.pop();
            }
            k--;

        }
        return cost;

    }
};
