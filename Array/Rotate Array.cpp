/* Author : Vansh Kumar
  Date : 2025-10-15
  Description: leetcode-189. Rotate Array
*/
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        // Brute force T.C-> O(n) , S.C-> O(k)
        /*int n= arr.size();
        k = k % n;
        if(k==0) return;

        vector<int> temp(k);
        //Store last k elements
        for(int i = 0; i<k; i++){//O(k)
            temp[i] = arr[n-k+i];
        }

        //Shift remaining elements right by k
        for(int i=n-k-1; i>=0; i--){//O(n-k)
            arr[i+k] = arr[i];
        }
        // Put temp elements in front
        for(int i= 0; i<k; i++){//O(k)
            arr[i] = temp[i];
        }*/

        //Optimal approach T.C-> O(1) , S.C-> O(1)
        int n= arr.size();
        k = k % n; // handle cases where k > n
        if(k==0) return;

        //reverse whole array
        reverse(arr.begin(), arr.end());
        //Step 2: Reverse first k elements
        reverse( arr.begin() , arr.begin()+k);
        // Step 3: Reverse remaining n - k elements
        reverse(arr.begin()+k , arr.end());
    }
};
