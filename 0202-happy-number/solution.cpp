class Solution {
public:
    void getdigits(int n,vector<int>&ans){
        ans ={};

        while(n>0){
            int dig =n%10;
            ans.push_back(dig);
            n/= 10;
        }

    }
    bool isHappy(int n) {
        unordered_map<int,bool>mp;
        int val = n;
        vector<int>digits;
        while(mp[val] ==false && val != 1){
            mp[val] = true;
            getdigits(val,digits);
            int sum = 0;
            for(auto i:digits){
                sum += i*i;
            }
            val = sum;
        }
        if (val == 1)return true;
        return false;
    }
};
