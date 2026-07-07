class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0){
            if(nums[i-1]<nums[i]){
                i--;
                break;
            }
            i--;
        }
        int num = nums[i];
    
        int j =nums.size()-1;
        for(j;j>i;j--){
            if(nums[j]>nums[i]){
                break;
            }
        }
        if(j != i){
            nums[i] = nums[j];
            nums[j] = num;
            sort(nums.begin()+i+1,nums.end());

        }
        else{
            sort(nums.begin()+j,nums.end());
        }
        
        
        return;

    }
};