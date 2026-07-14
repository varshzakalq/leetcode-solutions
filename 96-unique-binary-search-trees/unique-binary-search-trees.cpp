class Solution {
public:
    int numTrees(int n) {
        if(n <1)return n;
        vector<int>ans(n+1,0);
        ans[0] =1;
        ans[1 ]=1;
        for(int i =2;i<n+1;i++){
            for(int j =1;j<i+1;j++){
                ans[i] += ans[j-1]*ans[i-j];
            }
        }
        return ans[n];
    }
};