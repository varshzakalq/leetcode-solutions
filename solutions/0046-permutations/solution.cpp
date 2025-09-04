class Solution {
public:
    void getper(int idx, vector<int> &arr, vector<vector<int>> &ans){
         int n = arr.size();
        if(idx == n){ans.push_back(arr);
                    return;}
        
        for(int i =idx; i<n; i++){
            swap(arr[idx], arr[i]);
            getper(idx+1,arr,ans);
            swap (arr[idx],arr[i] );
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getper(0,nums,ans);
        return ans;
        
    }
};
