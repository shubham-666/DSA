func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    // Check overlap on X-axis
    xOverlap := rec1[0] < rec2[2] && rec2[0] < rec1[2]

    // Check overlap on Y-axis
    yOverlap := rec1[1] < rec2[3] && rec2[1] < rec1[3]

    return xOverlap && yOverlap
}