class Solution {
public:
    bool caneatall(vector<int>& piles, int h,int k){
        long long  hourspend = 0;
        for(auto p :piles){
            hourspend +=(p+k-1)/k;
        }
        return hourspend <=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low =1;
        long long high = *std::max_element(piles.begin(),piles.end());
        long long ans = high;
        while(high>=low){
            long long mid = low +(high-low)/2;
            if(caneatall(piles,h,mid)){
                ans = mid;
                high= mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
