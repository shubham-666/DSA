class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        n = len(arr)
        INF = n + 1

        # best[i] = minimum length of a target-sum subarray
        # completely inside arr[0..i-1]
        best = [INF] * (n + 1)

        ans = INF
        left = 0
        curr_sum = 0
        

        for right in range(n):
            curr_sum += arr[right]

            while curr_sum > target:
                curr_sum -= arr[left]
                left += 1

            if curr_sum == target:
                length = right - left + 1

                # Best previous subarray must end before 'left'
                if best[left] != INF:
                    ans = min(ans, best[left] + length)

                # Update best for prefix ending at 'right'
                best[right + 1] = min(best[right], length)
            else:
                best[right + 1] = best[right]

        return -1 if ans == INF else ans