func nodesBetweenCriticalPoints(head *ListNode) []int {
    minDistance := int(^uint(0) >> 1)
    first := -1
    prevCritical := -1

    prev := head
    curr := head.Next
    pos := 1

    for curr != nil && curr.Next != nil {
        next := curr.Next

        // Check local maxima or local minima
        isCritical := (curr.Val > prev.Val && curr.Val > next.Val) ||
            (curr.Val < prev.Val && curr.Val < next.Val)

        if isCritical {
            if first == -1 {
                // First critical point
                first = pos
            } else {
                // Distance from previous critical point
                distance := pos - prevCritical

                if distance < minDistance {
                    minDistance = distance
                }
            }

            prevCritical = pos
        }

        prev = curr
        curr = next
        pos++
    }

    // Fewer than two critical points
    if first == -1 || first == prevCritical {
        return []int{-1, -1}
    }

    maxDistance := prevCritical - first

    return []int{minDistance, maxDistance}
}