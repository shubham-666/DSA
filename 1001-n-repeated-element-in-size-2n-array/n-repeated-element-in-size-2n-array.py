class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums) // 2
        count = {}

        for num in nums:
            count[num] = count.get(num, 0) + 1

            if count[num] == n:
                return num