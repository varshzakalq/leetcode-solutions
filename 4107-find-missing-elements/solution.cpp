class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int st = nums[0];
        int end= nums[nums.size()-1];
        int i=0;
        vector<int> ans;
        while(st <end){
            if(st != nums[i] ){
                ans.push_back(st);
                st++;
            }
            else{
                st++;
                i++;
            }
            }
        return ans;
    
    
    }
};
