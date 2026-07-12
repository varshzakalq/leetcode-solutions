class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map <int,int> mp;
        int count = 1;
        for(int i =0;i<arr.size();i++){
            if(mp.find(temp[i]) == mp.end()){
                 mp[temp[i]] =count++;
                 cout<<i;
            }               
        }
        for(int i =0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};