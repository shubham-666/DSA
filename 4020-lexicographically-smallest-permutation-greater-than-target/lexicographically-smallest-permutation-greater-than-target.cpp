class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        
        vector<int> count(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }

        int n = s.size();
        string prefix;

        // Store states where we can make the answer greater
        int bestPos = -1;
        vector<int> bestCount;

        for (int i = 0; i < n; i++) {
            int current = target[i] - 'a';

            // At this position, check if a greater character is available.
            for (int ch = current + 1; ch < 26; ch++) {
                if (count[ch] > 0) {
                    bestPos = i;
                    bestCount = count;
                    break;
                }
            }

            // Try to keep the prefix equal to target.
            if (count[current] == 0) {
                break;
            }

            prefix += target[i];
            count[current]--;
        }

        // s itself is a permutation equal to target.
        // We still need a strictly greater permutation.
        if (bestPos == -1) {
            return "";
        }

        // Rebuild prefix before bestPos.
        string answer;
        vector<int> remaining(26, 0);

        for (char ch : s) {
            remaining[ch - 'a']++;
        }

        for (int i = 0; i < bestPos; i++) {
            int ch = target[i] - 'a';

            if (remaining[ch] == 0) {
                return "";
            }

            answer += target[i];
            remaining[ch]--;
        }

        // Put the smallest character greater than target[bestPos].
        int current = target[bestPos] - 'a';

        for (int ch = current + 1; ch < 26; ch++) {
            if (remaining[ch] > 0) {
                answer += char('a' + ch);
                remaining[ch]--;
                break;
            }
        }

        // Append remaining characters in lexicographically smallest order.
        for (int ch = 0; ch < 26; ch++) {
            answer += string(remaining[ch], char('a' + ch));
        }

        return answer;
    }
};