class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        current = []

        def backtrack():
            if len(current) == len(nums):
                result.append(current.copy())
                return

            for num in nums:
                if num in current:
                    continue

                current.append(num)
                backtrack()
                current.pop()

        backtrack()
        return result