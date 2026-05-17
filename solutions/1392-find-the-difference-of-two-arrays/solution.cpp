class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        // 2. Initialize the answer vector with 2 empty rows
        vector<vector<int>> ans(2);
        
        // 3. Find elements in s1 that are NOT in s2
        for (int num : s1) {
            if (s2.find(num) == s2.end()) {
                ans[0].push_back(num);
            }
        }
        
        // 4. Find elements in s2 that are NOT in s1
        for (int num : s2) {
            if (s1.find(num) == s1.end()) {
                ans[1].push_back(num);
            }
        }
        
        return ans;
    }

};
