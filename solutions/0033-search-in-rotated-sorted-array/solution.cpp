class Solution {
public:
    int findPeak(vector<int>& nums){
        int st = 0;
        int n = nums.size()-1;
        int end = nums.size()-1;

        if(end ==0)return st;
        else if(end ==1){
            
            return (nums[st]>nums[end])? st:end;}
        
        while(st <= end){
            int mid = st + (end - st) / 2;
            
            // Check if mid is the peak, safely handling edge boundaries
            bool leftCheck = (mid == 0) || (nums[mid] > nums[mid - 1]);
            bool rightCheck = (mid == n - 1) || (nums[mid] > nums[mid + 1]);
            
            if(leftCheck && rightCheck){
                return mid;
            }
            
            // If mid is in the left sorted portion, peak is further right
            if(nums[mid] >= nums[0]){
                st = mid + 1;
            }
            // If mid is in the right sorted portion, peak is further left
            else{
                end = mid - 1;
            }
        }
        return 0;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() ==1)return (nums[0] == target)?0:-1;
        int st =0;
        int end = nums.size()-1;
        int pivot = findPeak(nums);
        if (target >= nums[0] && target <= nums[pivot]){
            end = pivot;
        }
        else{
            st = pivot+1;
        }
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) return mid;
            
            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return -1;


    }
};
