func shortestToChar(s string, c byte) []int {
    n := len(s)
    ans := make([]int, n)

    // Left to right
    distance := n

    for i := 0; i < n; i++ {
        if s[i] == c {
            distance = 0
        } else {
            distance++
        }

        ans[i] = distance
    }

    // Right to left
    distance = n

    for i := n - 1; i >= 0; i-- {
        if s[i] == c {
            distance = 0
        } else {
            distance++
        }

        if distance < ans[i] {
            ans[i] = distance
        }
    }

    return ans
}