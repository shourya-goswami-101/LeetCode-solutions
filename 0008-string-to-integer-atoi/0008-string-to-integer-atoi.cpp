class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Determine sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Convert digits
        long long result = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            result = result * 10 + digit;

            // 4. Check overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }

            if (result * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return result * sign;
    }
};