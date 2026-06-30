class Solution {
public:
    int climb(int n){
        if(n ==1 || n  ==0)return 1;
        if(n ==2)return 2;
        int curr =2;
        int prev = 1;
        
        for(int i =3;i<=n;i++){
            int temp = curr;
            curr = curr +prev;
            prev = temp;
        }
        return curr;
    }
    int climbStairs(int n) {
        return climb(n);
        
    }
};
