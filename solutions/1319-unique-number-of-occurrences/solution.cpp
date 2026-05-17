class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int ,int>m1;
        for(int i =0;i<arr.size();i++){
            m1[arr[i]]++;
        }
        set <int> s1;
        for(auto i =m1.begin();i!= m1.end();i++){
            if(s1.find(i->second)!= s1.end())return false;
            s1.insert(i->second);
        }
        return true;








    }
};
