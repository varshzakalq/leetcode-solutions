class Solution {
public:
set <vector<int>> s;
    void cs(vector <int> &arr, int tar, int i , vector <int> tracker, vector<vector<int>> &ans){
        if (i == arr.size() || tar<0){
            return;
        }
        if(tar == 0){
            if(s.find(tracker) == s.end())
              {  ans.push_back(tracker);
                s.insert(tracker);}
            return;
        }
        
        
        

        
        tracker.push_back(arr[i]);
        cs(arr, tar-arr[i], i+1,tracker, ans);
        cs(arr, tar-arr[i], i,tracker, ans);
        tracker.pop_back();
        cs(arr, tar, i+1,tracker, ans);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tracker;
        vector<vector <int>> ans;
        cs(candidates, target, 0, tracker, ans);
        return ans;
        
    }
};
