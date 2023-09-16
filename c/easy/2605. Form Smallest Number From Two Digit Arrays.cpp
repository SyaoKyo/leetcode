/* 2605. Form Smallest Number From Two Digit Arrays
 * Given two arrays of unique digits nums1 and nums2,
 * return the smallest number that contains at least one digit from each array.
 * Example 1:
 * Input: nums1 = [4,1,3], nums2 = [5,7]
 * Output: 15
 * Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2.
 * It can be proven that 15 is the smallest number we can have.
 *
 * Example 2:
 * Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
 * Output: 3
 * Explanation: The number 3 contains the digit 3 which exists in both arrays.
 *
 * Constraints:
 * 1 <= nums1.length, nums2.length <= 9
 * 1 <= nums1[i], nums2[i] <= 9
 * All digits in each array are unique.
 * */

class Solution {
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2) {
        auto min1 = *min_element(nums1.begin(), nums1.end());
        auto min2 = *min_element(nums2.begin(), nums2.end());

        int sameMinNum = INT32_MAX;
        int mergeMinNum = -1;
        for (auto num1 : nums1) {
            for (auto num2 : nums2) {
                if (num1 == num2) {
                    sameMinNum = min(num1, sameMinNum);
                }
            }
        }

        if (min1 < min2) {
            mergeMinNum = min1 * 10 + min2;
        } else {
            mergeMinNum = min2 * 10 + min1;
        }
        return min(mergeMinNum, sameMinNum);
    }
};

//时间0 ms，击败100%
//内存21.2 MB，击败48.75%