func earliestFinishTime(landStartTime []int, landDuration []int,
	waterStartTime []int, waterDuration []int) int {

	ans := int(1e9)

	// Land ride first, then water ride
	for i := 0; i < len(landStartTime); i++ {
		landFinish := landStartTime[i] + landDuration[i]

		for j := 0; j < len(waterStartTime); j++ {
			waterStart := max(landFinish, waterStartTime[j])
			finish := waterStart + waterDuration[j]

			ans = min(ans, finish)
		}
	}

	// Water ride first, then land ride
	for i := 0; i < len(waterStartTime); i++ {
		waterFinish := waterStartTime[i] + waterDuration[i]

		for j := 0; j < len(landStartTime); j++ {
			landStart := max(waterFinish, landStartTime[j])
			finish := landStart + landDuration[j]

			ans = min(ans, finish)
		}
	}

	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}