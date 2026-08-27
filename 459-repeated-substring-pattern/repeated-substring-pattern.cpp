class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int length = 1; length <= n / 2; length++) {
            if (n % length != 0) {
                continue;
            }

            bool valid = true;

            for (int i = length; i < n; i++) {
                if (s[i] != s[i % length]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                return true;
            }
        }

        return false;
    }
};