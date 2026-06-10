class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string pre = strs[0];
        for(int i =0 ;i<strs.size();i++){
            string temp = strs[i];
            string newpre = "";
            for(int j =0; j<pre.size();j++){
                if(temp [j] != pre[j]){
                    pre = newpre;
                }
                else{
                    newpre += temp[j];
                }
            }
        }
        return pre;
    }
};
