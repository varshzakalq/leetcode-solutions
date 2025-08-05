class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int l = part.length();
        while(s.find(part)<n){
            int i = s.find(part);
            s.erase(i,l);

        }
        return s;
        
    }
};
