class Solution {
public:
    int lengthOfLastWord(string s) {
        int count =0;
        bool flag = false;
        for(int i =0; i<s.size();i++){
            if(s[i] != ' '&& flag == false)count ++;
            else if(s[i] != ' '&& flag == true){
                flag = false;
                count = 1;
            }
            else if(s[i] == ' '){
                flag = true;
            }
        }
        return count;
    }
};
