func uniqueMorseRepresentations(words []string) int {
    morse := []string{
        ".-", "-...", "-.-.", "-..", ".", "..-.",
        "--.", "....", "..", ".---", "-.-", ".-..",
        "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-",
        "-.--", "--..",
    }

    unique := make(map[string]bool)

    for _, word := range words {
        transformation := ""

        for _, ch := range word {
            transformation += morse[ch-'a']
        }

        unique[transformation] = true
    }

    return len(unique)
}