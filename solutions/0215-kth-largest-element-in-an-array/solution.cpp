class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::make_heap(nums.begin(),nums.end());
        
        while(k>1){
            std::pop_heap(nums.begin(), nums.end());
            nums.pop_back();
           
           
            k--;
        }
        return nums[0];
    }
};
