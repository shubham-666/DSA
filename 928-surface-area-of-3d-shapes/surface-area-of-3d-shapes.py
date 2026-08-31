class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        area = 0

        for i in range(n):
            for j in range(n):
                h = grid[i][j]

                if h == 0:
                    continue

                # Top + bottom + 4 sides
                area += 4 * h + 2

                # Shared face with the right tower
                if j + 1 < n:
                    area -= 2 * min(h, grid[i][j + 1])

                # Shared face with the bottom tower
                if i + 1 < n:
                    area -= 2 * min(h, grid[i + 1][j])

        return area
        