class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        rows = []

        for i, row in enumerate(mat):
            soldiers = sum(row)
            rows.append((soldiers, i))

        rows.sort()

        return [rows[i][1] for i in range(k)]