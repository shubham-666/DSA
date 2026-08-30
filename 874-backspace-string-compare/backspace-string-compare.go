func backspaceCompare(s string, t string) bool {
    i := len(s) - 1
    j := len(t) - 1

    skipS, skipT := 0, 0

    for i >= 0 || j >= 0 {
        // Find next valid character in s
        for i >= 0 {
            if s[i] == '#' {
                skipS++
                i--
            } else if skipS > 0 {
                skipS--
                i--
            } else {
                break
            }
        }

        // Find next valid character in t
        for j >= 0 {
            if t[j] == '#' {
                skipT++
                j--
            } else if skipT > 0 {
                skipT--
                j--
            } else {
                break
            }
        }

        // One string has a character, other doesn't
        if i < 0 || j < 0 {
            return i == j
        }

        // Characters don't match
        if s[i] != t[j] {
            return false
        }

        i--
        j--
    }

    return true
}