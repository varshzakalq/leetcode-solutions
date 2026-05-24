class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int prev1 = nums[0];
        if(nums.size()== 1)return prev1;
        int  prev= nums[1];
        if(prev1 >prev){
            prev = prev1;
        }
        for(int i = 2; i<nums.size();i++){
            if(prev1+nums[i]>prev){
                int temp = prev;
                prev = prev1+nums[i];
                prev1 =temp;
            }
            else{
                prev1 = prev;
                
            }

        }
        return max(prev ,prev1);
    }
};
