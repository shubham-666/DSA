class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26] = {0};

        for (char c : chars) {
            freq[c - 'a']++;
        }

        int ans = 0;

        for (string word : words) {
            int count[26] = {0};
            bool good = true;

            for (char c : word) {
                count[c - 'a']++;

                if (count[c - 'a'] > freq[c - 'a']) {
                    good = false;
                    break;
                }
            }

            if (good) {
                ans += word.length();
            }
        }

        return ans;
    }
};