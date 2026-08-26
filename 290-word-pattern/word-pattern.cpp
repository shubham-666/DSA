class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream stream(s);
        string word;

        // Split the string into words
        while (stream >> word) {
            words.push_back(word);
        }

        // Number of words must match pattern length
        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char currentChar = pattern[i];
            string currentWord = words[i];

            // Check character -> word mapping
            if (charToWord.count(currentChar) &&
                charToWord[currentChar] != currentWord) {
                return false;
            }

            // Check word -> character mapping
            if (wordToChar.count(currentWord) &&
                wordToChar[currentWord] != currentChar) {
                return false;
            }

            charToWord[currentChar] = currentWord;
            wordToChar[currentWord] = currentChar;
        }

        return true;
    }
};