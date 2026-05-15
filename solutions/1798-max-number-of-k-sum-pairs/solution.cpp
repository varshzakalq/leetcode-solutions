class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int pairs =0 ;
        unordered_map<int,int> freq;
        for(int i =0; i <nums.size();i++){
            int r = k- nums[i];
            if(freq[r]>0){
                freq[r] --;
                pairs ++;
            
            }
            else
                freq[nums[i]] ++;

        }
        return pairs;

        
    }
};
