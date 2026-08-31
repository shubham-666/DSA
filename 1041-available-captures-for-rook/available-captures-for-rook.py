class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        # Find the rook
        for r in range(8):
            for c in range(8):
                if board[r][c] == 'R':
                    rook_r, rook_c = r, c

        directions = [
            (-1, 0),  # up
            (1, 0),   # down
            (0, -1),  # left
            (0, 1)    # right
        ]

        count = 0

        for dr, dc in directions:
            r = rook_r + dr
            c = rook_c + dc

            while 0 <= r < 8 and 0 <= c < 8:
                if board[r][c] == 'p':
                    count += 1
                    break

                if board[r][c] == 'B':
                    break

                r += dr
                c += dc

        return count