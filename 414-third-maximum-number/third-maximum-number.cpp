class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int number : nums) {
            // Ignore duplicates
            if (number == first || number == second || number == third) {
                continue;
            }

            if (number > first) {
                third = second;
                second = first;
                first = number;
            }
            else if (number > second) {
                third = second;
                second = number;
            }
            else if (number > third) {
                third = number;
            }
        }

        if (third == LLONG_MIN) {
            return first;
        }

        return third;
    }
};