func stoneGameV(stoneValue []int) int {
	n := len(stoneValue)

	prefix := make([]int64, n+1)
	for i := 0; i < n; i++ {
		prefix[i+1] = prefix[i] + int64(stoneValue[i])
	}

	sum := func(l, r int) int64 {
		return prefix[r+1] - prefix[l]
	}

	// dp[l][r] = maximum score Alice can obtain from stoneValue[l:r+1]
	dp := make([][]int64, n)
	for i := range dp {
		dp[i] = make([]int64, n)
	}

	for length := 2; length <= n; length++ {
		for l := 0; l+length <= n; l++ {
			r := l + length - 1

			for k := l; k < r; k++ {
				leftSum := sum(l, k)
				rightSum := sum(k+1, r)

				if leftSum < rightSum {
					dp[l][r] = max64(
						dp[l][r],
						leftSum+dp[l][k],
					)
				} else if rightSum < leftSum {
					dp[l][r] = max64(
						dp[l][r],
						rightSum+dp[k+1][r],
					)
				} else {
					// Equal sums: Alice chooses either side.
					dp[l][r] = max64(
						dp[l][r],
						leftSum+dp[l][k],
						rightSum+dp[k+1][r],
					)
				}
			}
		}
	}

	return int(dp[0][n-1])
}

func max64(values ...int64) int64 {
	result := values[0]
	for _, v := range values[1:] {
		if v > result {
			result = v
		}
	}
	return result
}