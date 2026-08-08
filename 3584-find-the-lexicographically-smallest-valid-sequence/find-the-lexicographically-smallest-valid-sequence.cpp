class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> suf(m + 1);
        suf[m] = n;
        for (int j = m - 1; j >= 0; j--) {
            int i = suf[j + 1] - 1;
            while (i >= 0 && word1[i] != word2[j]) i--;
            suf[j] = i;
        }

        vector<int> ans;
        ans.reserve(m);
        int i = 0, j = 0;
        bool used = false;

        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                i++; j++;
            } else if (!used && i + 1 <= suf[j + 1]) {
                ans.push_back(i);
                used = true;
                i++; j++;
            } else {
                i++;
            }
        }

        if ((int)ans.size() < m) return {};
        return ans;
    }
};