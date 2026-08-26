class Solution {
public:
   int firstUniqChar(string s) {
        vector<int> count(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            count[ch - 'a']++;
        }

        // Find the first character with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};