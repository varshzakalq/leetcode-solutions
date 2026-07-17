class Solution {
public:
    void restore (string &s,string current,vector<string>&ans,int id,int segments){
        if(segments == 4 && id == s.size()){
            current.pop_back();
            ans.push_back(current);
            return;
        }
        if(segments >3 || id>= s.size()){
            return;
        }
        string prev;
        string segment_val ="";
        for(int i =id;i<s.size();i++){
            segment_val +=s[i];
            if((i>id &&segment_val[0] =='0') || stoi(segment_val) >255){
                return;
            }
            prev = current;
            current += segment_val;
            current += '.';
            restore(s,current,ans,i+1,segments +1);
            current.pop_back();
            current = prev;
        }

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string current;
        if(s.size() <4 || s.size()>12){
            return ans;
        }
        restore(s,current,ans,0,0);
        return ans;
    }
};