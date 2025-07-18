class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int cs = 0;
        for(int ele : nums){
            cs += ele;
            maxsum = max(cs, maxsum);
            if(cs<0){
                cs = 0;
            }

        }
        return maxsum;
        
    }
};
