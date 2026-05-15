class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int flag = false;
        if (nums.size()<3){
            return false;
        }
        int s = nums[0];
        int s2 = INT_MAX;
        for (int i =1; i<nums.size(); i++){
            if(nums[i]<=s){
                s = nums[i];
            }
            else if(nums[i]<=s2)
                s2 = nums[i];
            else
                return true;
        }

        return flag;
    }
};
