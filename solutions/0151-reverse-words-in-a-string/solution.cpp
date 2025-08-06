class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        string ans = "";
        int i = 0;
        while (i<n){
            string word= "";
            
            while(i <n && s[i] != ' '){
                word+= s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if (word.length() != 0){
                ans+= ' ' + word;
            }

            i++;
        }
        return ans.substr(1);
        
    }
};
