/* Author : Vansh Kumar
  Date : 2025-10-15
  Description: leetcode-349. Intersection of Two Arrays
  GFG- https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-arrays-with-duplicate-elements/1
*/
//T.C = O( n + m) , S.C =O( 1 )
class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int n = a.size();
        int  m = b.size();
        int i=0 , j=0;
        vector<int> ans;
        while(i < n && j < m){
            if( a[i] < b[j]){
                i++;
            }
            else if(b[j] < a[i]){
                j++;
            } else{
                if(ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
