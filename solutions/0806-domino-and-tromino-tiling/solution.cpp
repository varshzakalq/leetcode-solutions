class Solution {
public:
    int numTilings(int n) {
        long long arr[5] = {1,2,5,11,24};
        if(n <=5){
            return arr[n-1];
        }
        for(int i =6; i<=n; i++){
            long long t = arr[1]+arr[2] + arr[3]*2+arr[4];
            for(int j =0;j<4;j++){
                arr[j] = arr[j+1];
            }
            arr[4] = t% 1000000007;
        }
        return arr[4];
        
    }
};
