/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: Leetcode problem-179. Largest Number
  GFG - Form the Largest Numbe.
*/
//Leetcode Solution:
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for( auto x : nums){
            arr.push_back(to_string(x));
        }
      /* auto myComparater = []( int& a , int& b){
          string s1 = to_string(a);
          string s2 =  to_string(b);
           return s1+s2 > s2+s1;
      }*/

        auto myComparater = [](string& s1 , string& s2){
            return s1+s2 > s2+s1;
        };
        sort( arr.begin() , arr.end() , myComparater);
        if(arr[0] == "0"){
            return "0";
        }
        string result = "";
        for(string& s : arr){
          //result += to_string(arr);
            result += s;
        }
        return result;
    }
};


//GFG solution
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> nums;
        for(auto x : arr){
            nums.push_back(to_string(x));
        }
        auto myComprater = []( string& s1 , string& s2){
            /*if( (s1 + s2) > ( s1 + s2) ){
                return true;
            }
            return false;
            */
            return s1+s2 > s2+s1;
        };
        sort(begin(nums), end(nums) , myComprater);
        if(nums[0]=="0"){
            return "0";
        }
        string result = "";
        for(string& s : nums){
            result += s;
        }   
        return result;
    }
};
