class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count =0;
        while(c>0||b>0||a>0){
            int bitc = c&1;
            int bitb = b&1;
            int bita = a&1;
            if(bitc ==0 ){
                count += (bita+bitb);
            }
            else {
                if(bita ==0 &&bitb ==0)
                    count++;
            }
            
            a >>=1;
            b >>=1;
            c >>=1;
        }
        return count;
    }
};
