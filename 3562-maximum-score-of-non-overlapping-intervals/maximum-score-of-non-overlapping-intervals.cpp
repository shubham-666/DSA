class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> indices;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;   // lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {right, left, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][1],
                intervals[i][0],
                intervals[i][2],
                i
            });
        }

        // Sort by ending position
        sort(a.begin(), a.end());

        vector<long long> ends(n);
        for (int i = 0; i < n; i++)
            ends[i] = a[i][0];

        // prev[i] = number of intervals before i whose
        // ending point is strictly less than a[i]'s starting point.
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            long long left = a[i][1];

            prev[i] = lower_bound(
                ends.begin(),
                ends.begin() + i,
                left
            ) - ends.begin();
        }

        // dp[i][k]:
        // best result using first i intervals,
        // choosing at most k intervals.
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {
            long long right = a[i - 1][0];
            long long left = a[i - 1][1];
            long long weight = a[i - 1][2];
            int idx = (int)a[i - 1][3];

            for (int k = 1; k <= 4; k++) {

                // Option 1: Don't take current interval
                dp[i][k] = dp[i - 1][k];

                // Option 2: Take current interval
                int p = prev[i - 1];

                State candidate = dp[p][k - 1];

                candidate.score += weight;
                candidate.indices.push_back(idx);

                // The answer must be sorted by original indices
                sort(candidate.indices.begin(), candidate.indices.end());

                if (better(candidate, dp[i][k])) {
                    dp[i][k] = candidate;
                }
            }
        }

        return dp[n][4].indices;
    }
};