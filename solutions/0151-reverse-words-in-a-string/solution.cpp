class Solution {
public:
    string reverseWords(string s) {
        string temp = " ";
        string result = "";
        for( int i =0; i<s.size();i++){
            if(s[i] ==' ' && temp != " "){
                result = temp + result;
                temp = " ";
            }
            else if (s[i] != ' '){
                temp.push_back(s[i]);
                }
        }
        if(temp != " ")
            result = temp + result;
        result.erase(result.begin());

        return result;

    }
};
