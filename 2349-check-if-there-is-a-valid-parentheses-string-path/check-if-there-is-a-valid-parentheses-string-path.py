class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])

        # A valid parentheses string must have even length
        if (m + n - 1) % 2 == 1:
            return False

        # Starting with ')' is immediately invalid
        if grid[0][0] == ')':
            return False

        # dp[j] = set of possible balances at column j
        dp = [set() for _ in range(n)]

        dp[0].add(1)

        for i in range(m):
            for j in range(n):
                
                if i == 0 and j == 0:
                    continue

                current = set()

                # Come from top
                if i > 0:
                    current.update(dp[j])

                # Come from left
                if j > 0:
                    current.update(dp[j - 1])

                new_balances = set()

                for balance in current:
                    if grid[i][j] == '(':
                        new_balance = balance + 1
                    else:
                        new_balance = balance - 1

                    # Balance can never be negative
                    if new_balance >= 0:
                        new_balances.add(new_balance)

                dp[j] = new_balances

        return 0 in dp[n - 1]