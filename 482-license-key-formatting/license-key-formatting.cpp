class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean;

        // Remove dashes and convert letters to uppercase
        for (char ch : s) {
            if (ch != '-') {
                clean.push_back(toupper(ch));
            }
        }

        string result;
        int count = 0;

        // Build groups from right to left
        for (int i = clean.size() - 1; i >= 0; i--) {
            if (count == k) {
                result.push_back('-');
                count = 0;
            }

            result.push_back(clean[i]);
            count++;
        }

        // We built the string backwards
        reverse(result.begin(), result.end());

        return result;
    }
};