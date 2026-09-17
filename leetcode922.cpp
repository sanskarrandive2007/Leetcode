// Q] Sort Array By Parity II :-

// Given an array of integers nums, half of the integers in nums are odd, and half of the integers are even.

// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

// Return any answer array that satisfies this condition.

// Example 1:

// Input: nums = [4,2,5,7]
// Output: [4,5,2,7]
// Explanation: [4,2,5,7] is a valid answer because:
// - nums[0] is even and nums[1] is odd
// - nums[2] is even and nums[3] is odd
// Example 2:

// Input: nums = [2,3]
// Output: [2,3]
// Explanation: [2,3] is a valid answer because:
// - nums[0] is even and nums[1] is odd

// Constraints:

// 2 <= nums.length <= 2 * 104
// nums.length is even.
// Half of the integers in nums are even.
// 0 <= nums[i] <= 1000

//Solution Of This Question :-

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                ans.push_back(even[i / 2]);
            }
            else{
                ans.push_back(odd[i / 2]);
            }
        }
        return ans;
        
    }
};