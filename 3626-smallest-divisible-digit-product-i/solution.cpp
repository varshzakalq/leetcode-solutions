class Solution {
public:
int getprd(int n){
    int ans =1;
    if(n==0){
        return 0;
    }
    while(n>0){
        
        ans *= (n%10);
        n/=10;
    }
    return ans;
}
    int smallestNumber(int n, int t) {
        
        while(true){
            int num= getprd(n);
            if(num % t==0){
                return n;
            }
            n++;
        }
        return 0;
    }
};
