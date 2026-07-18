class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest;
        for(int i = 0;i<nums.size()-2;i++){
            int n1 = nums[i];
            int k = i+1;
            int j = nums.size()-1;
            if(i ==0)
                closest = n1 +nums[k]+nums[j];
            while(k<j){
                
                int sum = n1 + nums[j]+nums[k];
                if(abs(closest -target) >abs(sum-target)){
                    closest = sum;
                }
                if(sum == target)return target;
                else if(sum <target){
                    k++;
                }
                else{
                    j--;
                }
                
            }
        }
        return closest;
    }
};