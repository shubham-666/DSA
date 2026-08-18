class Solution {
public:
    int largestAltitude(vector<int>& gain) {
         int a = 0;
         int h =0;
         for(int x : gain){
            a += x;
            h = max(h,a);
         }
         return h;
    }
};