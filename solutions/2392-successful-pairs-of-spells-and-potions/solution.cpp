class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector <int> ans;
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<spells.size();i++){
            int st = 0;
            int end = potions.size()-1;
            ans.push_back(0);
            while(st<=end){
                int mid = st +(end -st)/2;
                long long s = (long long)potions[mid]*spells[i];
                if(s>=success){
                    ans[i] = potions.size()-mid;
                    
                    end = mid-1;
                }
                else{
                    st = mid+1;
                }
            }
        }
        return ans;

    }
};
