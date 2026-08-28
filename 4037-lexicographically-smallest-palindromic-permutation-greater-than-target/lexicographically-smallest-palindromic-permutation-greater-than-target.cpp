class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Count characters in s
        vector<int> count(26, 0);
        for (char ch : s) {
            count[ch - 'a']++;
        }

        // A palindrome can have at most one character with odd frequency
        int oddChar = -1;

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                if (oddChar != -1) {
                    return "";
                }
                oddChar = i;
            }
        }

        // Characters available for the first half
        vector<int> halfCount(26, 0);
        for (int i = 0; i < 26; i++) {
            halfCount[i] = count[i] / 2;
        }

        int halfLength = n / 2;

        auto buildPalindrome = [&](const string& half) {
            string middle = "";

            if (oddChar != -1) {
                middle += char('a' + oddChar);
            }

            return half + middle + string(half.rbegin(), half.rend());
        };

        /*
         * First check whether target's first half can be used directly.
         *
         * This is important because an equal first half can still produce
         * a palindrome greater than target due to the second half.
         */
        string targetHalf = target.substr(0, halfLength);

        vector<int> remaining = halfCount;
        bool possible = true;

        for (char ch : targetHalf) {
            int index = ch - 'a';

            if (remaining[index] == 0) {
                possible = false;
                break;
            }

            remaining[index]--;
        }

        if (possible) {
            string candidate = buildPalindrome(targetHalf);

            if (candidate > target) {
                return candidate;
            }
        }

        /*
         * Find the smallest half that is strictly greater than targetHalf.
         *
         * We try the rightmost possible position to increase, then choose
         * the smallest available character greater than target[i].
         */
        vector<vector<int>> prefix(halfLength + 1, vector<int>(26, 0));

        for (int i = 0; i < halfLength; i++) {
            prefix[i + 1] = prefix[i];
            prefix[i + 1][targetHalf[i] - 'a']++;
        }

        for (int i = halfLength - 1; i >= 0; i--) {
            vector<int> available(26);

            bool validPrefix = true;

            for (int j = 0; j < 26; j++) {
                available[j] = halfCount[j] - prefix[i][j];

                if (available[j] < 0) {
                    validPrefix = false;
                }
            }

            if (!validPrefix) {
                continue;
            }

            int current = targetHalf[i] - 'a';

            // Pick the smallest character greater than targetHalf[i]
            for (int next = current + 1; next < 26; next++) {
                if (available[next] == 0) {
                    continue;
                }

                available[next]--;

                string half = targetHalf.substr(0, i);
                half += char('a' + next);

                // Fill the remaining positions with smallest characters
                for (int j = 0; j < 26; j++) {
                    half += string(available[j], char('a' + j));
                }

                string candidate = buildPalindrome(half);

                if (candidate > target) {
                    return candidate;
                }
            }
        }

        return "";
    }
};