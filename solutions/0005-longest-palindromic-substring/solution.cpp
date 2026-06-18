class Solution {
public:
    int expand(int left ,int right , string &s){
        while(left>=0 && right < s.size() && s[right]== s[left]){
           left --;
           right ++;
        }
        return right -left -1;
        
    }
    string longestPalindrome(string s) {
        int l =s.size();
        if(l == 0|| l==1 )return s;
        int maxlen = 1;
        int start = 0;
        for(int i=0; i<s.size();i++){
            int l1 = expand(i,i,s);
            int l2 = expand(i,i+1,s);
            int m = max(l1,l2);
            if(m>maxlen){
                maxlen = m;
                start = i -(m-1)/2;
            }
        }
        return s.substr(start,maxlen);
               
                
            
                
       
       
    }
};
