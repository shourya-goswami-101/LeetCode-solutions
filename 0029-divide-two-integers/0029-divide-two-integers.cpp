class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine whether answer should be negative
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long before taking absolute value
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Keep doubling divisor
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract largest possible multiple
            a -= temp;
            quotient += multiple;
        }

        if (negative)
            quotient = -quotient;

        // Clamp to 32-bit integer range
        if (quotient > INT_MAX)
            return INT_MAX;

        if (quotient < INT_MIN)
            return INT_MIN;

        return (int)quotient;
    }
};