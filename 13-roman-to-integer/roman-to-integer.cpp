class Solution {
public:
//will it
    int romanToInt(string s) {
        int ans =0;
        int prev = 0;
        int curr;
        for(int j = 0;j<s.size();j++){
            char i = s[j];
            if( i == 'I'){
               curr = 1; 
            }
            else if(i =='V'){
                curr = 5;
            }
            else if(i =='X'){
                curr = 10;
            }
            else if(i =='L'){
                curr = 50;
            }
            else if(i =='C'){
                curr = 100;
            }
            else if(i =='D'){
                curr = 500;
            }
            else if(i =='M'){
                curr = 1000;
            }
            if(prev ==0){
                prev = curr;
            }
            else{
                if(prev <curr){
                    ans = ans -prev;
                    prev = curr;
                }
                else{
                    ans = ans +prev;
                    prev = curr;
                }

            }
            

        }
        return ans+prev;
    }
};