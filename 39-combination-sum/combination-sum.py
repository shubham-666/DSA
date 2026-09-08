class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        current = []

        def backtrack(start, remaining):
            if remaining == 0:
                result.append(current.copy())
                return

            for i in range(start, len(candidates)):
                num = candidates[i]

                if num > remaining:
                    break

                current.append(num)

                # i, not i + 1, because we can reuse the same number
                backtrack(i, remaining - num)

                current.pop()

        backtrack(0, target)
        return result