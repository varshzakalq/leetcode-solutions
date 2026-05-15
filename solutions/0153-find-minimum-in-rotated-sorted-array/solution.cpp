class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int st = 0;
        int end = nums.size() - 1;

        while(st < end){

            int mid = st + (end - st) / 2;

            // minimum is in right half
            if(nums[mid] > nums[end]){
                st = mid + 1;
            }

            // minimum is in left half (including mid)
            else{
                end = mid;
            }
        }

        return nums[st];
    }
};
