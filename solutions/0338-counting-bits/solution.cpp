class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        
        for(int i =0; i<n+1;i++){
            int c =0; 
            int a = i;
            while(a>0){
                c += a%2;
                a = a/2;
            }
            ans[i] = c;
        }
        return ans;
    }
};
