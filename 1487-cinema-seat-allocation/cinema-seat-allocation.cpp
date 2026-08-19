class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &x : reservedSeats) {
            int row = x[0], seat = x[1];

            if (seat >= 2 && seat <= 9)
                mp[row] |= (1 << seat);
        }

        long long ans = 2LL * (n - mp.size());

        int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int mid  = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, mask] : mp) {
            bool l = (mask & left) == 0;
            bool r = (mask & right) == 0;

            if (l && r)
                ans += 2;
            else if (l || r || (mask & mid) == 0)
                ans += 1;
        }

        return ans;
    }
};