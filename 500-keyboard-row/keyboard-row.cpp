class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> result;

        for (string word : words) {
            int row = -1;
            bool valid = true;

            for (char ch : word) {
                ch = tolower(ch);

                int currentRow;

                if (row1.find(ch) != string::npos) {
                    currentRow = 1;
                } else if (row2.find(ch) != string::npos) {
                    currentRow = 2;
                } else {
                    currentRow = 3;
                }

                if (row == -1) {
                    row = currentRow;
                } else if (row != currentRow) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result.push_back(word);
            }
        }

        return result;
    }
};