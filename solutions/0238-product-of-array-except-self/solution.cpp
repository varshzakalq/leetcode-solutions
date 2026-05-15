class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre =1;
        int suff =1;
        vector<int> out;
    for (int i =0 ; i<nums.size();i++){
        out.push_back(pre);
        pre *= nums[i];

    }
    for(int j =nums.size()-1; j>=0;j--){
        out[j] *= suff;
        suff *= nums[j];

    }
    return out;
    }
};
