class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int ,bool> m1;
        for (int i =0; i<nums.size();i++){
            if(m1[nums[i]]== false){
                
                m1[nums[i] ]= true;}
            else{
                
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
        
    }
};
