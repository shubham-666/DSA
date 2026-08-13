package main

import (
	"fmt"
	"strconv"
	"strings"
)

func reformatDate(date string) string {
	parts := strings.Split(date, " ")

	// Day: "20th" -> "20"
	dayStr := parts[0]
	dayStr = strings.TrimSuffix(dayStr, "st")
	dayStr = strings.TrimSuffix(dayStr, "nd")
	dayStr = strings.TrimSuffix(dayStr, "rd")
	dayStr = strings.TrimSuffix(dayStr, "th")

	day, _ := strconv.Atoi(dayStr)

	monthMap := map[string]int{
		"Jan": 1,
		"Feb": 2,
		"Mar": 3,
		"Apr": 4,
		"May": 5,
		"Jun": 6,
		"Jul": 7,
		"Aug": 8,
		"Sep": 9,
		"Oct": 10,
		"Nov": 11,
		"Dec": 12,
	}

	month := monthMap[parts[1]]
	year := parts[2]

	return fmt.Sprintf("%s-%02d-%02d", year, month, day)
}

