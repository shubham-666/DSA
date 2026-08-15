func minimumCost(cost []int) int {
	sort.Slice(cost, func(i, j int) bool {
		return cost[i] > cost[j]
	})

	total := 0

	for i, price := range cost {
		// Every 3rd candy is free
		if i%3 != 2 {
			total += price
		}
	}

	return total
}