class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.size(); i++) {
            char first = s[i];
            char second = t[i];

            if (sToT.count(first) && sToT[first] != second) {
                return false;
            }

            if (tToS.count(second) && tToS[second] != first) {
                return false;
            }

            sToT[first] = second;
            tToS[second] = first;
        }

        return true;
    }
};