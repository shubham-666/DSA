class Solution {
public:
    char findTheDifference(string s, string t) {
        char reslut = 0;
        for(char ch : s){
            reslut ^= ch;
        }
        for(char ch: t){
            reslut ^= ch;
        }
        return reslut;
    }
};