class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i =0;
        int j =0; 
        int c0 =0;
        int c1 =0;
        while(c0<k && j<nums.size()){
            if(nums[j] ==1)c1++;
            else c0 ++;
            j++;
        }
        while(j<nums.size()&&nums[j] ==1 ){
            c1++;
            j++;
        }
        int max = c1+c0;
        while(j<nums.size()){
            while(c0>k && i<=j){
                if(nums[i] ==1)c1--;
                else c0 --;
                i++;
            }
            if(nums[j] == 1)c1++;
            else c0++;
            j++;
            if(c0 <= k && c1+c0 >max) max = c1 +c0;

        }
        return max;
    }
};
