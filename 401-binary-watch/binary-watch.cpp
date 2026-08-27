class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                
                int totalBits = countBits(hour) + countBits(minute);

                if (totalBits == turnedOn) {
                    string time = to_string(hour) + ":";

                    if (minute < 10) {
                        time += "0";
                    }

                    time += to_string(minute);

                    result.push_back(time);
                }
            }
        }

        return result;
    }

private:
    int countBits(int number) {
        int count = 0;

        while (number > 0) {
            count += number & 1;
            number >>= 1;
        }

        return count;
    }
};