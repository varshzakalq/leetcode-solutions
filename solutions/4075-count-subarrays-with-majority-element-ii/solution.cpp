

class Solution {
    vector<int> bit;
    int offset;

    void update(int idx, int val) {
        for (; idx < bit.size(); idx += idx & -idx)
            bit[idx] += val;
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
public:

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // Offset ensures indices are positive for the BIT
        offset = n + 1;
        bit.assign(2 * n + 2, 0);

        long long count = 0;
        int current_sum = 0;

        // Base case: prefix sum of 0 exists before the start of the array
        update(0 + offset, 1);

        for (int x : nums) {
            // Transform: target = 1, others = -1
            current_sum += (x == target) ? 1 : -1;

            // We need: (current_prefix_sum - previous_prefix_sum) > 0
            // Which means: previous_prefix_sum < current_prefix_sum
            count += query(current_sum + offset - 1);

            // Update BIT with current prefix sum
            update(current_sum + offset, 1);
        }

        return count;
    
    }
};
