class Solution {
public:
    void findper(int st, vector<vector<int>> &ans,vector<int> curr,vector<int>nums){
        if(nums.size()== 0){
            ans.push_back(curr);
            return;
        }
        for(int i =st;i<nums.size();i++){
            if(i>st&& nums[i-1]== nums[i])continue;
            curr.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            findper(st,ans,curr,nums);
            int val =curr.back();
            curr.pop_back();
            nums.insert(nums.begin()+i,val);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int>curr;
        int st =0;

        findper(st,ans,curr,nums);
        return ans;
    }
};
