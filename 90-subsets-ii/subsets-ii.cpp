class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        int stId =0;
        sort(nums.begin(),nums.end());
        backtrack(nums,ans, current,stId);
        return ans;
    }
    void backtrack(vector<int>& nums,vector<vector<int>> &ans, vector<int> &current,int stId){
        ans.push_back(current);
        for(int i = stId;i<nums.size();i++){

            if(i>stId && nums[i-1]== nums[i])continue;
            current.push_back(nums[i]);
            backtrack(nums,ans,current,i+1);
            current.pop_back();
        }
    }
};