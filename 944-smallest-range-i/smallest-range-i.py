class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        minimum = min(nums)
        maximum = max(nums)

        return max(0, maximum - minimum - 2 * k)