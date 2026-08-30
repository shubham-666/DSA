class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        int m = image.size();
        int n = image[0].size();

        // Out of bounds
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }

        // Different color
        if (image[r][c] != oldColor) {
            return;
        }

        // Change color
        image[r][c] = newColor;

        // Four directions
        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        // Already the same color
        if (oldColor == color) {
            return image;
        }

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};