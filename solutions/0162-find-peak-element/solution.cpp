class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;
        
        while (st < end) {
            int mid = st + (end - st) / 2;
            
            // If mid element is less than the next element, 
            // the peak must be in the right half.
            if (nums[mid] < nums[mid + 1]) {
                st = mid + 1;
            } 
            // Otherwise, the peak is either at mid or to the left.
            else {
                end = mid;
            }
        }
        
        // When st == end, they will point to a peak element.
        return st;
    }
};
