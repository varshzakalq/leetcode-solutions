class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        vector<pair<int,int>> v(n);
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i =0; i<nums1.size();i++){
            v[i].first = nums2[i];
            v[i].second = nums1[i];
        }
        sort(v.rbegin(),v.rend());
        long long maxscore = 0;
        long long curr= 0;
        
        for(int i =0; i<n;i++){
            curr += v[i].second;
            int currmin = v[i].first;
            q.push(v[i].second);
            if(q.size()>k){
                int a = q.top();
                curr -= a;
                q.pop();
            }
            if(q.size() ==k ){
               if(maxscore <curr*currmin)maxscore = curr*currmin;
            }
        }
        return maxscore;
    }
};
