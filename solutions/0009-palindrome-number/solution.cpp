class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 ||(x%10 == 0 &&x != 0))return false;
        int num = x;
        long reverse = 0;
        while(num>0){
            int last = num%10;
            reverse = last +(reverse*10);
            num/=10;
        }
        return reverse == x;
    }
};
