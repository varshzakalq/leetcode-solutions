class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int hindex = citations.size();
        for(auto i:citations){
            if(i >= hindex){
                return hindex;
            }
            else{
                hindex--;
            }
        }
        return 0;
    }
};
