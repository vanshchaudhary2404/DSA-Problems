/* Author : Vansh Kumar
  Date : 2025-10-15
  Description: leetcode- 88. Merge Sorted Array
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;          // last valid element in nums1
        int j = n - 1;          // last element in nums2
        int k = m + n - 1;      // last index of nums1 (final position)

        // Merge from the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy any remaining elements from nums2, if nums2 is still left to fill in nums1.
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
