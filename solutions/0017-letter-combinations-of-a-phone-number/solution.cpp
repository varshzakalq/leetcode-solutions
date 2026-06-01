class Solution {
public:
vector <string>ans;
    void help(int idx,string &digits,map<char,string>&m1,string &curr_str ){
        //accept
        if(idx ==digits.size()){
            ans.push_back(curr_str);
            return;
        }
        char ch = digits[idx];
        for(char l:m1[ch]){
            curr_str += l;
            help(idx+1,digits,m1,curr_str);
            curr_str.pop_back();
        }
        //reject

    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()== 0)return ans;
      map<char,string>m1;
        m1['2'] = {"abc"};
        m1['3'] = {"def"};
        m1['4'] = {"ghi"};
        m1['5'] = {"jkl"};
        m1['6'] = {"mno"};
        m1['7'] = {"pqrs"};
        m1['8'] = {"tuv"};
        m1['9'] = {"wxyz"};


      string curr_str ;
      help(0,digits,m1,curr_str);
      return ans;



    }
};
