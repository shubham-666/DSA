from typing import List


class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
        n = len(nums)

        # tree[p] = [product of segment % k, count of prefix products]
        prod = [0] * (4 * n)
        cnt = [[0] * k for _ in range(4 * n)]

        def merge(p):
            l = p * 2
            r = l + 1

            prod[p] = (prod[l] * prod[r]) % k

            for x in range(k):
                cnt[p][x] = cnt[l][x]

            # Prefix starts in right child only after
            # taking the whole left child.
            for x in range(k):
                y = (prod[l] * x) % k
                cnt[p][y] += cnt[r][x]

        def build(p, lo, hi):
            if lo == hi:
                v = nums[lo] % k
                prod[p] = v
                cnt[p][v] = 1
                return

            mid = (lo + hi) // 2

            build(p * 2, lo, mid)
            build(p * 2 + 1, mid + 1, hi)

            merge(p)

        def update(p, lo, hi, idx, val):
            if lo == hi:
                v = val % k

                prod[p] = v

                # Clear old counts
                for i in range(k):
                    cnt[p][i] = 0

                cnt[p][v] = 1
                return

            mid = (lo + hi) // 2

            if idx <= mid:
                update(p * 2, lo, mid, idx, val)
            else:
                update(p * 2 + 1, mid + 1, hi, idx, val)

            merge(p)

        def query(p, lo, hi, ql, qr):
            if ql <= lo and hi <= qr:
                return prod[p], cnt[p][:]

            mid = (lo + hi) // 2

            if qr <= mid:
                return query(p * 2, lo, mid, ql, qr)

            if ql > mid:
                return query(p * 2 + 1, mid + 1, hi, ql, qr)

            lp, lc = query(p * 2, lo, mid, ql, qr)
            rp, rc = query(p * 2 + 1, mid + 1, hi, ql, qr)

            # Merge queried left + queried right
            res = lc[:]

            for x in range(k):
                y = (lp * x) % k
                res[y] += rc[x]

            return (lp * rp) % k, res

        build(1, 0, n - 1)

        ans = []

        for index, value, start, x in queries:
            # Update persists for all future queries
            update(1, 0, n - 1, index, value)

            # After removing prefix [0 ... start-1],
            # valid answers are non-empty prefixes of [start ... n-1].
            _, c = query(1, 0, n - 1, start, n - 1)

            ans.append(c[x])

        return ans