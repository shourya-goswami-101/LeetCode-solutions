class Solution {
public:

    pair<int, int> expand(string& s, int left, int right) {

        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {

            left--;
            right++;
        }

        // The last expansion was invalid,
        // so move back inside the palindrome.
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {

        if (s.length() <= 1)
            return s;

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {

            // Odd-length palindrome
            auto odd = expand(s, i, i);

            // Even-length palindrome
            auto even = expand(s, i, i + 1);

            if (odd.second - odd.first >
                end - start) {

                start = odd.first;
                end = odd.second;
            }

            if (even.second - even.first >
                end - start) {

                start = even.first;
                end = even.second;
            }
        }

        return s.substr(start, end - start + 1);
    }
};