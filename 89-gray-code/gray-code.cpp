class Solution {
public:

    vector<int> grayCode(int n) {
        vector<int> ans;
        int i =0;
        while(i<=pow(2,n)-1){
            int j = i;
            ans.push_back(j^(j>>1));
            i++;
        }
        return ans;
    }
};