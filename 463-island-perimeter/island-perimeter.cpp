class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (grid[row][col] == 0) {
                    continue;
                }

                // Every land cell starts with 4 sides
                perimeter += 4;

                // Remove one side for every adjacent land cell
                for (auto& direction : directions) {
                    int newRow = row + direction[0];
                    int newCol = col + direction[1];

                    if (newRow >= 0 && newRow < rows &&
                        newCol >= 0 && newCol < cols &&
                        grid[newRow][newCol] == 1) {
                        perimeter--;
                    }
                }
            }
        }

        return perimeter;
    }
};
