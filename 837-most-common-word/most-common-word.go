func mostCommonWord(paragraph string, banned []string) string {
    bannedSet := make(map[string]bool)

    for _, word := range banned {
        bannedSet[word] = true
    }

    freq := make(map[string]int)
    word := ""

    for i := 0; i <= len(paragraph); i++ {
        if i < len(paragraph) && ((paragraph[i] >= 'a' && paragraph[i] <= 'z') ||
            (paragraph[i] >= 'A' && paragraph[i] <= 'Z')) {

            ch := paragraph[i]

            if ch >= 'A' && ch <= 'Z' {
                ch = ch - 'A' + 'a'
            }

            word += string(ch)
        } else {
            if word != "" && !bannedSet[word] {
                freq[word]++
            }

            word = ""
        }
    }

    answer := ""
    maxFreq := 0

    for word, count := range freq {
        if count > maxFreq {
            maxFreq = count
            answer = word
        }
    }

    return answer
}