class Solution {
public:
    int reverse(int n) {
 
    int ans = 0;
    

    while (n != 0)
    {
        // for  digit to binary no
        //   int bit =n & 1;
        // ans =(bit *pow(10, i)) + ans;
        // n = n >>1;
        // i++;

        /* code */
        int digit = n % 10;
          if((ans > INT_MAX/10) || (ans < INT_MIN/10)){
              return 0;
          }
       
            ans = ( ans*10)+ digit;
        
        n = n / 10;
       
    } return ans;
    // cout << "Answer is: " << ans << endl;

        
    }
};