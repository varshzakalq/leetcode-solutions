class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int h =0;
        int temp=0;
        for(int i=0; i<gain.size();i++){
            temp += gain[i];
            if(temp >h) h= temp;
        }
        return h;
    }
};
