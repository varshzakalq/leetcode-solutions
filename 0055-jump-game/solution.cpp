class Solution {
public:
    bool jump(int i ,vector<int>& nums){
        if(i>=nums.size() ||(nums[i]==0&& i != nums.size()-1))return false;
        if(i == nums.size()-1) return true;
        int k = nums[i];
        while(k>0){
            
            bool found = jump(i+k,nums);
            k--;
            
            if(found)return true;
        }
        return false;

    }
    bool canJump(vector<int>& nums) {
        if (nums.size()==1)return true;
        int max_reach = nums[0];
        for(int i =1;i<=max_reach;i++){
            max_reach = max(max_reach,(i+nums[i]));
            if(max_reach>=nums.size()-1)return true;
        }
        return false;
    }
};
