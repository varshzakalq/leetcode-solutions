class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int>mp;
        for(int i =0 ;i<nums.size();i++){
            mp[nums[i]]++;

        }
        
        int majele;
        int maj= -1;
        for(const auto& [key ,value]: mp){
            if(value> maj){
                maj = value;
                majele = key;

            }
        }
        return majele;
    }
};