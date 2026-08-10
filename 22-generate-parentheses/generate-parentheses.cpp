class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;

        backtrack(n, 0, 0, cur, ans);

        return ans;
    }

    void backtrack(int n, int open, int close,
                   string& cur, vector<string>& ans) {

        // Complete valid combination
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }

        // Add opening bracket
        if (open < n) {
            cur.push_back('(');
            backtrack(n, open + 1, close, cur, ans);
            cur.pop_back();
        }

        // Add closing bracket
        if (close < open) {
            cur.push_back(')');
            backtrack(n, open, close + 1, cur, ans);
            cur.pop_back();
        }
    }
};