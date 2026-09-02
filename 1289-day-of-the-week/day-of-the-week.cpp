class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> week = {
            "Sunday", "Monday", "Tuesday", "Wednesday",
            "Thursday", "Friday", "Saturday"
        };

        int days = 0;

        // Count complete years
        for (int y = 1971; y < year; y++) {
            days += isLeap(y) ? 366 : 365;
        }

        // Days in each month
        vector<int> monthDays = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        if (isLeap(year))
            monthDays[1] = 29;

        // Count complete months
        for (int m = 1; m < month; m++) {
            days += monthDays[m - 1];
        }

        // Add days before the given day
        days += day - 1;

        // 1971-01-01 was Friday (index 5)
        return week[(5 + days) % 7];
    }

private:
    bool isLeap(int year) {
        return (year % 400 == 0) ||
               (year % 4 == 0 && year % 100 != 0);
    }
};