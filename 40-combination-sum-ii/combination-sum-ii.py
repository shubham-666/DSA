class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        current = []

        def backtrack(start, remaining):
            if remaining == 0:
                result.append(current.copy())
                return

            for i in range(start, len(candidates)):
                # Skip duplicate values at the same recursion level
                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                # Since the array is sorted
                if candidates[i] > remaining:
                    break

                current.append(candidates[i])

                # i + 1 because each element can be used only once
                backtrack(i + 1, remaining - candidates[i])

                current.pop()

        backtrack(0, target)
        return result