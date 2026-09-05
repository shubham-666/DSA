class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        cur = 0
        min_sum = 0

        for x in nums:
            cur += x
            min_sum = min(min_sum, cur)

        return 1 - min_sum