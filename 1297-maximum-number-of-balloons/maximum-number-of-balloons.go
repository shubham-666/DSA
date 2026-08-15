func maxNumberOfBalloons(text string) int {
    count := make([]int, 26)

    for _, ch := range text {
        count[ch-'a']++
    }

    // "balloon" needs:
    // b:1, a:1, l:2, o:2, n:1
    count['l'-'a'] /= 2
    count['o'-'a'] /= 2

    ans := count['b'-'a']

    if count['a'-'a'] < ans {
        ans = count['a'-'a']
    }
    if count['l'-'a'] < ans {
        ans = count['l'-'a']
    }
    if count['o'-'a'] < ans {
        ans = count['o'-'a']
    }
    if count['n'-'a'] < ans {
        ans = count['n'-'a']
    }

    return ans
}

