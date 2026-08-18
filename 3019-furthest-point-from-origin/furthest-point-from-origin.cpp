class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l =0, r=0, b=0;
        for(char c : moves){
            if(c== 'L')
            l++;
            else if(c== 'R')
            r++;
            else 
            b++;
        }
        int gR= r + b -l;
        int gL = l + b -r;
        return max(abs(gR), abs(gL));
    }
};