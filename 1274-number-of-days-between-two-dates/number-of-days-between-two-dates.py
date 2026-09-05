class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        days = [31, 28, 31, 30, 31, 30, 
                31, 31, 30, 31, 30, 31]

        def isLeap(y):
            return y % 400 == 0 or (y % 4 == 0 and y % 100 != 0)

        def toDays(date):
            y, m, d = map(int, date.split('-'))

            total = 0

            # Days of previous years
            for year in range(1, y):
                total += 366 if isLeap(year) else 365

            # Days of previous months
            for month in range(1, m):
                total += days[month - 1]
                if month == 2 and isLeap(y):
                    total += 1

            total += d
            return total

        return abs(toDays(date1) - toDays(date2))