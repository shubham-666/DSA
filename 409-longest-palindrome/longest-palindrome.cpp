class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);

        for (char ch : s) {
            count[ch]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (int frequency : count) {
            length += (frequency / 2) * 2;

            if (frequency % 2 == 1) {
                hasOdd = true;
            }
        }

        // One odd character can be placed in the center
        if (hasOdd) {
            length++;
        }

        return length;
    }
};