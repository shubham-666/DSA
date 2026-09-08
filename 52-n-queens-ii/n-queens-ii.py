class Solution:
    def totalNQueens(self, n: int) -> int:
        count = 0

        cols = set()
        diagonals = set()       # row - col
        anti_diagonals = set()  # row + col

        def backtrack(row):
            nonlocal count

            if row == n:
                count += 1
                return

            for col in range(n):
                if col in cols:
                    continue

                if row - col in diagonals:
                    continue

                if row + col in anti_diagonals:
                    continue

                # Place queen
                cols.add(col)
                diagonals.add(row - col)
                anti_diagonals.add(row + col)

                backtrack(row + 1)

                # Remove queen
                cols.remove(col)
                diagonals.remove(row - col)
                anti_diagonals.remove(row + col)

        backtrack(0)

        return count