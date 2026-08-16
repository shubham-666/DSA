func stoneGameIX(stones []int) bool {
    cnt := [3]int{}

    for _, stone := range stones {
        cnt[stone%3]++
    }

    // If the number of stones divisible by 3 is even,
    // Alice wins when both remainder-1 and remainder-2 stones exist.
    if cnt[0]%2 == 0 {
        return cnt[1] > 0 && cnt[2] > 0
    }

    // If cnt[0] is odd, Alice needs a sufficiently large
    // imbalance between remainder-1 and remainder-2 stones.
    return abs(cnt[1]-cnt[2]) > 2
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}