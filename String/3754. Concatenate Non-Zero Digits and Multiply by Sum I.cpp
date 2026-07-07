class Solution {
public:
    long long sumAndMultiply(int n) {
        /*
        if(n==0)
            return 0;
        //for reverse.
        int rev =0;
        while( n>0){
            rev = rev*10 +(n%10);
            n /= 10;
        }

        long long x =0;
        int sum = 0;
        while(rev>0){
            int digit = rev%10;
            rev /= 10;
            if( digit == 0)
                continue;

            x = x*10 + digit;
            sum += digit;
        }
        return (x * sum);
        */

        string s = to_string(n);

        long long x =0;
        int sum =0;

        for( char ch : s){
            if( ch == '0'){
                continue;
            }
            int digit = ch - '0';

            x = x*10 + digit;
            sum += digit;
        }
        return (x* sum);
    }
};
