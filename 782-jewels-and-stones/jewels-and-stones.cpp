class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool isJewell[128] = {};

        for (char ch : jewels) {
            isJewell[ch] = true;
        }

        int count = 0;

        for (char ch : stones) {
            if (isJewell[ch]) {
                count++;
            }
        }

        return count;
    }
};