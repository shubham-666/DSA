class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        

        vector<int> count(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }

        string result;
        vector<pair<int, vector<int>>> choices;

        // Try to match target as much as possible
        for (int i = 0; i < target.size(); i++) {
            int current = target[i] - 'a';

            // Save this position if we can increase the character here
            for (int ch = current + 1; ch < 26; ch++) {
                if (count[ch] > 0) {
                    choices.push_back({i, count});
                    break;
                }
            }

            // Match target[i] if possible
            if (count[current] > 0) {
                result.push_back(target[i]);
                count[current]--;
            } else {
                break;
            }
        }

        // If we matched the complete target, we still need
        // a strictly greater permutation, so backtrack.
        int matched = result.size();

        if (matched == target.size()) {
            // All characters are used, so target itself is a permutation.
            // Need to find a position where we can make it larger.
        }

        // Try backtracking from right to left
        for (int i = min(matched, (int)target.size() - 1); i >= 0; i--) {
            // Restore characters from the suffix
            if (i < result.size()) {
                count[result[i] - 'a']++;
            }

            // Find smallest available character greater than target[i]
            int greaterChar = -1;

            for (int ch = target[i] - 'a' + 1; ch < 26; ch++) {
                if (count[ch] > 0) {
                    greaterChar = ch;
                    break;
                }
            }

            if (greaterChar != -1) {
                string answer = result.substr(0, i);

                answer.push_back('a' + greaterChar);
                count[greaterChar]--;

                // Fill the remaining positions with smallest characters
                for (int ch = 0; ch < 26; ch++) {
                    answer.append(count[ch], 'a' + ch);
                }

                return answer;
            }
        }

        return "";
    }
};


