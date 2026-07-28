class Solution {
public:
   int divide(int dividend, int divisor) {
        // Handle 32-bit signed integer overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Result sign is negative if exactly one operand is negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to avoid overflow when taking absolute values
        long long absDividend = std::labs((long long)dividend);
        long long absDivisor = std::labs((long long)divisor);

        long long quotient = 0;

        // Exponential bit-shift division
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Double the divisor until it exceeds the remaining dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            absDividend -= tempDivisor;
            quotient += multiple;
        }

        return isNegative ? -quotient : quotient;
    }
};
