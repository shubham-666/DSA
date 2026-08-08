class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict;

        for (string &word : words)
            dict.insert(word);

        vector<string> ans;

        for (string &word : words) {
            dict.erase(word);

            int n = word.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;

            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {

                    if (!dp[j])
                        continue;

                    if (dict.count(word.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }

            if (dp[n])
                ans.push_back(word);

            dict.insert(word);
        }

        return ans;
    }
};