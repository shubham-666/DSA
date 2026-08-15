func longestSubsequence(nums []int) int {
    n := len(nums)

    xor := 0
    for _, x := range nums {
        xor ^= x
    }

    // If total XOR is non-zero, take all elements.
    if xor != 0 {
        return n
    }

    // Total XOR is zero. Remove one non-zero element;
    // the remaining XOR becomes that element, hence non-zero.
    for _, x := range nums {
        if x != 0 {
            return n - 1
        }
    }

    // All elements are zero.
    return 0
}