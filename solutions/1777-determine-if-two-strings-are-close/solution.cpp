class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())return false;
        map <int,int>m1;
        map <int,int>m2;
        for(int i =0;i<word1.size();i++){
            m1[word1[i]]++;
        }
        for(int i =0;i<word2.size();i++){
            m2[word2[i]]++;
        }
        for(auto &p : m1) {
            if(m2.find(p.first) == m2.end()) return false;
        }
        
        vector <int> d1;
        vector <int> d2;
        int o =0;
        for(auto i = m1.begin();i!= m1.end(); i++){
            
            d1.push_back(i->second);
        }
        o=0;
        for(auto i = m2.begin();i!= m2.end(); i++){
            d2.push_back(i->second);
        }
        sort(d1.begin(),d1.end());
        sort(d2.begin(),d2.end());
        if(d1 == d2)return true;
        return false;


    }
};
