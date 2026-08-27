class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        bool negative = num < 0;

        long long number = abs((long long)num);
        string result;

        while (number > 0) {
            result.push_back('0' + (number % 7));
            number /= 7;
        }

        if (negative) {
            result.push_back('-');
        }

        reverse(result.begin(), result.end());

        return result;
    }
};