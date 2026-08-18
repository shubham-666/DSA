class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();

        int n = grid[0].size();
        vector<int> arr;
     for(int i =0; i < m; i ++){
        for(int j =0; j< n; j++){
        arr.push_back(grid[i][j]);

        }

     }

     int t = m *n;
     k %= t;

     vector<int> shifted(t);
     for(int i =0; i  < t; i ++){
        shifted[(i + k) % t]= arr[i];
     }

    for( int i =0; i <m; i++){
        for(int j =0; j<n; j++){
            grid[i][j] = shifted[i * n + j];
        }
    }
        return grid;
    }
};