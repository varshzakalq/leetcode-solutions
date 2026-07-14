class Solution {
public:
    int reverse(int x) {
        string rev;
        if(x<0){
            if(x ==numeric_limits<int>::min())
                return 0;

            rev = to_string(-x);
            ::reverse(rev.begin(),rev.end());
            rev = "-" +rev;
        }
           
        else{
            rev = to_string(x);
            ::reverse(rev.begin(),rev.end());
        }
        try{
            int a = stoi(rev);
            return a;
        }
        catch(const std::out_of_range& e){
            return 0;
        }

            
    }
};