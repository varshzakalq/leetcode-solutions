class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <int> v(n,1);
        for(int i =1;i<m;i++){
            for(int i = 1;i<n;i++)
                v[i] = v[i]+v[i-1];
        }
        return v[n-1];
    }
};
