class Solution {
public:
    bool isvowel(char a){
        a = tolower(a);
        if(a == 'a' || a== 'e'||a == 'i' || a== 'o'|| a == 'u') return true;
        else return false;
    }
    string reverseVowels(string s) {
        vector <int> idx ;
        int i =0;
        int j =s.size() -1;
        while(i<j){
            if(isvowel(s[i])&& isvowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
                }
            if(!isvowel(s[i])) i++;
            if(!isvowel(s[j])) j--;
        }
        return s;
    }
};
