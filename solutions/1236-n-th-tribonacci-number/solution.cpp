class Solution {
public:
    int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        if(n == 0)return a;
        if (n == 1)return b;
        for(int i = 3; i<= n; i++){
            int t = a +b+c;
            a = b;
            b =c;
            c = t;
        }
        return c;
    }
};
