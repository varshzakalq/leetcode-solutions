class Solution {
public:
    void findComb(vector<int>& candidates,int start,int target,vector <int> current, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(current);
            return;
        }
        for(int i =start; i<candidates.size();i++){
            if(i>start && candidates[i]== candidates[i-1]){
                continue;
            }
            if(candidates[i]>target)break;
            current.push_back(candidates[i]);
            findComb(candidates,i+1,target-candidates[i],current,ans);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        
        // Start recursion from index 0
        findComb(candidates, 0, target, current, ans);
        return ans;
    }
};
