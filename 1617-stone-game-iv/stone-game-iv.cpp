class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp ( n+ 1, false);
        dp[0] = false;
        for(int i =1; i <=n; i ++){
            for(int j =1; j *j <= i; j++){
                int squrt = j *j;
                if(!dp[i - squrt]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

