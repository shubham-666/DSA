class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (auto &idx : indices) {
            row[idx[0]]++;
            col[idx[1]]++;
        }

        int oddRows = 0, oddCols = 0;

        for (int x : row)
            if (x % 2) oddRows++;

        for (int x : col)
            if (x % 2) oddCols++;

        int evenRows = m - oddRows;
        int evenCols = n - oddCols;

        return oddRows * evenCols + evenRows * oddCols;
    }
};