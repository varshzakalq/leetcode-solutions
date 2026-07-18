class Solution {
public:
    void qs(vector<int>& nums,int st,int end){
        if(st <end){
            int pi = nums[end];
            int i = st;
            int j = end-1;
            while(i<=j &&i<=end&& j>=st){
                while(i<end && nums[i] <=pi){
                    i++;
                }
                while(j>=0 &&nums[j]>pi){
                    j--;
                }
                if(i<j){
                    swap(nums[i],nums[j]);
                    
                }
                else{
                    swap(nums[i],nums[end]);
                }
            }
            qs(nums,st,i-1);
            qs(nums,i+1,end);
        }
    }
    void sortColors(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
        
    }
};