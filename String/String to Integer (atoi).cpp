/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-8. String to Integer (atoi)
*/
//difficult to do remind my words.
class Solution {
public:
    int myAtoi(string s) {
        //https://www.youtube.com/watch?v=qpjybiNliUA
        int i=0; 
        int l = s.length();

        while( i<l && isspace(s[i])){
            i++;
        }
        if( i==l){
            return 0;
        }
        bool negative = false;
        if(s[i] == '-'){
            negative = true;
            i++;
        }else if( s[i] == '+'){
            i++;
        }else if( !isdigit(s[i])){
            return 0;
        }
        if( i==l){
            return 0;
        }

        int val =0;
        int max = INT_MAX/10;
        int min = INT_MIN/10;

        while( i<l && isdigit(s[i])){
            int digit = s[i] -'0';

            //uverflow and underflow condition
            //check val is in the limits

            //1. Handle Overflow
            if( val > max){
                return INT_MAX;
            }else if( val == max && digit > 7){
                return INT_MAX;
            }

            //1. Handle Onderflow
            if( val < min){
                return INT_MIN;
            }else if( val == min && digit > 8){
                return INT_MIN;
            }


            if(negative){
                val = val*10 + (-digit);
            }else {
                val = val*10 + (digit);
            }
            i++;
        }
        return val;
    }

    /*By chatgpt
    int i = 0;
        int n = s.length();
        
        // 1. Skip leading spaces
        while (i < n && isspace(s[i])) {
            i++;
        }
        
        if (i == n) return 0;

        // 2. Handle sign
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        int result = 0;

        // 3. Process digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. Check overflow
            if (result > INT_MAX / 10 ||
               (result == INT_MAX / 10 && digit > 7)) {
                
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    */

};
