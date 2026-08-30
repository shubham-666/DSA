func numberOfLines(widths []int, s string) []int {
    lines := 1
    currentWidth := 0

    for _, ch := range s {
        w := widths[ch-'a']

        if currentWidth+w > 100 {
            lines++
            currentWidth = w
        } else {
            currentWidth += w
        }
    }

    return []int{lines, currentWidth}
}