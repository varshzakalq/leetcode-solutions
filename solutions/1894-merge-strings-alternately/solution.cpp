class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str;
        
        int i = 0 ;
        while (i<word1.length() && i<word2.length()){
            
            str += word1[i];
            str += word2[i++];

        }
        
       str += word1.substr(i);
       str += word2.substr(i);
        
        return str;
    }
};
