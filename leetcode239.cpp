// Q] What is the maximum sliding window?
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.



// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]


// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length


// Solution :-

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>nge(n);
        stack<int>p;
        
        for(int i = n - 1; i >= 0; i--){
            while(p.size() > 0 && nums[p.top()] <= nums[i]) p.pop();
            if(p.size() == 0){
                nge[i] = -1;
            }

            else{
                nge[i] = p.top();
            }
            p.push(i);
        }
        vector<int>ans(n-k+1);
        for(int i = 0; i < n-k+1; i++){
            int j = i;
            while(nge[j] != -1 && nge[j] < i + k)
            j = nge[j];

            ans[i] = nums[j];
        }
        return ans;   
    }
};