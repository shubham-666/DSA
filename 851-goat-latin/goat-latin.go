func toGoatLatin(sentence string) string {
    words := strings.Split(sentence, " ")
    result := make([]string, len(words))

    isVowel := func(ch byte) bool {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U'
    }

    for i, word := range words {
        if isVowel(word[0]) {
            word += "ma"
        } else {
            word = word[1:] + string(word[0]) + "ma"
        }

        // Word index starts from 1
        word += strings.Repeat("a", i+1)

        result[i] = word
    }

    return strings.Join(result, " ")
}