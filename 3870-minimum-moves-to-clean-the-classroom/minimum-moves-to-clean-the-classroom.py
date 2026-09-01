from typing import List
from collections import deque

class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        m = len(classroom)
        n = len(classroom[0])

        start = None
        litter = {}

        # Find start and assign an index to every litter cell
        for r in range(m):
            for c in range(n):
                if classroom[r][c] == 'S':
                    start = (r, c)
                elif classroom[r][c] == 'L':
                    litter[(r, c)] = len(litter)

        total_litter = len(litter)

        # No litter to collect
        if total_litter == 0:
            return 0

        full_mask = (1 << total_litter) - 1

        # best[r][c][mask] = maximum energy with which
        # we have reached this position and collected this mask.
        best = [
            [[-1] * (1 << total_litter) for _ in range(n)]
            for _ in range(m)
        ]

        sr, sc = start
        best[sr][sc][0] = energy

        # (r, c, mask, remaining_energy, moves)
        q = deque()
        q.append((sr, sc, 0, energy, 0))

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while q:
            r, c, mask, curr_energy, moves = q.popleft()

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                # Outside grid
                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    continue

                # Obstacle
                if classroom[nr][nc] == 'X':
                    continue

                # Cannot make a move with zero energy
                if curr_energy == 0:
                    continue

                new_energy = curr_energy - 1
                new_mask = mask

                # Collect litter
                if (nr, nc) in litter:
                    new_mask |= 1 << litter[(nr, nc)]

                # Reset energy on R
                if classroom[nr][nc] == 'R':
                    new_energy = energy

                new_moves = moves + 1

                # All litter collected
                if new_mask == full_mask:
                    return new_moves

                # If we've already reached this state with
                # equal or more energy, this state is useless.
                if best[nr][nc][new_mask] >= new_energy:
                    continue

                best[nr][nc][new_mask] = new_energy
                q.append((nr, nc, new_mask, new_energy, new_moves))

        return -1