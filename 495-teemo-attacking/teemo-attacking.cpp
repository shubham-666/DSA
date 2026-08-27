class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;

        for (int i = 0; i < timeSeries.size(); i++) {
            if (i == timeSeries.size() - 1) {
                total += duration;
            } else {
                total += min(duration, timeSeries[i + 1] - timeSeries[i]);
            }
        }

        return total;
    }
};