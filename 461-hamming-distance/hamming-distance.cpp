class Solution {
public:
    int hammingDistance(int x, int y) {
        int number = x ^ y;
        int distance = 0;

        while (number > 0) {
            distance += number & 1;
            number >>= 1;
        }

        return distance;
    }
};