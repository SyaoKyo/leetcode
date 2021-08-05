/*
* 18. 4Sum
* Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
* 0 <= a, b, c, d < n
* a, b, c, and d are distinct.
* nums[a] + nums[b] + nums[c] + nums[d] == target
* You may return the answer in any order.
*
* Example 1:
* Input: nums = [1,0,-1,0,-2,2], target = 0
* Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
* 
* Example 2:
* Input: nums = [2,2,2,2,2], target = 8
* Output: [[2,2,2,2]]
*  
* Constraints:
* 1 <= nums.length <= 200
* -10^9 <= nums[i] <= 10^9
* -10^9 <= target <= 10^9
*/

class Solution :
    def fourSum(self, nums: List[int], target : int)->List[List[int]] :
    nums.sort()
    nums_temp = list(set(nums))
    for num in nums_temp :
sum = 0
for n in nums :
if n == num :
    sum += 1
    elif n == num and sum > 4:
nums.remove(n)
else :
    break
    res = []
    for a in range(len(nums)) :
        for b in range(a + 1, len(nums)) :
            for c in range(b + 1, len(nums)) :
                for d in range(c + 1, len(nums)) :
                    if nums[a] + nums[b] + nums[c] + nums[d] == target :
                        ls = [nums[a], nums[b], nums[c], nums[d]]
                        if ls not in res :
res.append(ls)
return res