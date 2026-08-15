func mapWordWeights(words []string, weights []int) string {
    ans := ""

    for _, word := range words {
        sum := 0

        for _, ch := range word {
            sum += weights[ch-'a']
        }

        // Reverse alphabet:
        // 0 -> z, 1 -> y, ..., 25 -> a
        idx := sum % 26
        ans += string('z' - idx)
    }

    return ans
}