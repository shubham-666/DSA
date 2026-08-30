class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> required(26, 0);

        // Count required letters from licensePlate
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                ch = tolower(ch);
                required[ch - 'a']++;
            }
        }

        string answer = "";

        for (string word : words) {
            vector<int> count(26, 0);

            for (char ch : word) {
                count[ch - 'a']++;
            }

            bool complete = true;

            for (int i = 0; i < 26; i++) {
                if (count[i] < required[i]) {
                    complete = false;
                    break;
                }
            }

            if (complete && (answer.empty() || word.length() < answer.length())) {
                answer = word;
            }
        }

        return answer;
    }
};