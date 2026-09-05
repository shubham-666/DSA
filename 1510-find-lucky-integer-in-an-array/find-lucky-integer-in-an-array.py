class Solution:
    def findLucky(self, arr: List[int]) -> int:
        freq = {}

        for x in arr:
            freq[x] = freq.get(x, 0) + 1

        ans = -1

        for x in freq:
            if freq[x] == x:
                ans = max(ans, x)

        return ans