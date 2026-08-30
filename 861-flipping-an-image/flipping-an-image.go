func flipAndInvertImage(image [][]int) [][]int {
    for i := 0; i < len(image); i++ {
        left := 0
        right := len(image[i]) - 1

        for left <= right {
            image[i][left], image[i][right] =
                1-image[i][right], 1-image[i][left]

            left++
            right--
        }
    }

    return image
}