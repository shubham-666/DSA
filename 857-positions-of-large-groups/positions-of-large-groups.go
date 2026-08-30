func largeGroupPositions(s string) [][]int {
    result := [][]int{}
    n := len(s)

    start := 0

    for i := 1; i <= n; i++ {
        if i == n || s[i] != s[start] {
            if i-start >= 3 {
                result = append(result, []int{start, i - 1})
            }

            start = i
        }
    }

    return result
}