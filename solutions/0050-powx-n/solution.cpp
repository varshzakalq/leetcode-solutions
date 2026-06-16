class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 ||x ==1)return 1;
        long power =n;
        if(n<0){
            x = 1/x;
            power = -(static_cast <long>(n));

        }
        
        

        long double result = 1;
        long double curr_prd = x;
        while(power >0){
            if(power % 2 ==1){
                result *= curr_prd;
                power--;
            }
            curr_prd  = curr_prd*curr_prd;
            power/=2;
            
            
        }

        return result;

        
    }
};
