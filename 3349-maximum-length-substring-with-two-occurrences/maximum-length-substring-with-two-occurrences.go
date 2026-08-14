
func maximumLengthSubstring(s string) int {
    count := make(map[rune]int)
    start, maxLen := 0, 0
    for end, ch := range s {
        count[ch]++
        for {
            exceeds := false
            for _, c := range count {
                if c > 2 {
                    exceeds = true
                    break
                }
            }
            if !exceeds {
                break
            }
            startCh := rune(s[start])
            count[startCh]--
            if count[startCh] == 0 {
                delete(count, startCh)
            }
            start++
        }
        if currentLen := end - start + 1; currentLen > maxLen {
            maxLen = currentLen
        }
    }
    return maxLen
}
