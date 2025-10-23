/* Author : Vansh Kumar
  Date : 2025-10-24
  Description:Leetcode problem-60 kth permutation sequence.
  The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i=1; i<n; i++){
            fact = fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans ="";
        k = k-1; //o based indexing
        while(true){
            ans = ans + to_string(numbers[k/ fact]); // add first element in ans 
            numbers.erase(numbers.begin()+ (k / fact)); // remove the first element from numbers array
            if(numbers.size() == 0)
                break;
            k = k % fact;//find the next sequence
            fact = fact / numbers.size();
        }
        return ans;
    }
}
