class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);

        // Count available letters in magazine
        for (char ch : magazine) {
            count[ch - 'a']++;
        }

        // Use letters for ransomNote
        for (char ch : ransomNote) {
            count[ch - 'a']--;

            if (count[ch - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};