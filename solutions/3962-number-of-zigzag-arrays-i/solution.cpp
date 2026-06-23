class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD = 1000000007;
        int m = r - l + 1;
        
        // Handle edge case where length is 1
        if (n == 1) return m % MOD;

        // dp[v] represents the number of valid ways to reach value v
        vector<int> dp(m, 1);

        for (int i = 1; i < n; i++) {
            long long running_sum = 0;
            
            if (i % 2 == 1) {
                // Odd step: must go UP. 
                // Value v can only be reached from previous values strictly less than v.
                for (int v = 0; v < m; v++) {
                    long long next_sum = (running_sum + dp[v]) % MOD;
                    dp[v] = running_sum;
                    running_sum = next_sum;
                }
            } else {
                // Even step: must go DOWN.
                // Value v can only be reached from previous values strictly greater than v.
                for (int v = m - 1; v >= 0; v--) {
                    long long next_sum = (running_sum + dp[v]) % MOD;
                    dp[v] = running_sum;
                    running_sum = next_sum;
                }
            }
        }

        // Sum up all ending possibilities for this single pattern direction
        long long total_ways = 0;
        for (int v : dp) {
            total_ways = (total_ways + v) % MOD;
        }

        // Multiply by 2 to account for the opposite starting pattern (Down-Up-Down...)
        return (total_ways * 2) % MOD;
    }
};
