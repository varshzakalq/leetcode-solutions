class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
    # 1. Length condition check
        if len(s1) + len(s2) != len(s3):
            return False

        # Create a 2D DP table initialized to False
        # Rows represent s1 characters, columns represent s2 characters
        dp = [[False] * (len(s2) + 1) for _ in range(len(s1) + 1)]
        
        # Base case: Empty s1 and empty s2 can form empty s3
        dp[0][0] = True

        # Fill the first column (matching s3 using ONLY s1)
        for i in range(1, len(s1) + 1):
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]

        # Fill the first row (matching s3 using ONLY s2)
        for j in range(1, len(s2) + 1):
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]

        # Fill the rest of the DP table
        for i in range(1, len(s1) + 1):
            for j in range(1, len(s2) + 1):
                # Current character in s3 is at index (i + j - 1)
                match_s1 = dp[i-1][j] and s1[i-1] == s3[i+j-1]
                match_s2 = dp[i][j-1] and s2[j-1] == s3[i+j-1]
                
                dp[i][j] = match_s1 or match_s2

        # The bottom-right corner holds the definitive answer
        return dp[len(s1)][len(s2)]       