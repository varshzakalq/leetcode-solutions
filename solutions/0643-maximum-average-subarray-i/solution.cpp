class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double avg = 0;
        for(int j =0; j<k;j++){
            avg += nums[j];

        }
        double max =avg ;
        int j = k;
        for (int i =0; j<nums.size();i++){
            avg -= nums[i];
            avg += nums[j];
            j +=1;
            if(avg>max) max = avg;
        }
        return max/k;
    }
};
