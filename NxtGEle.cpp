// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
     
        int n = nums.size();
        vector<int>nge(n);
        stack<int>p;
        for(int i = n - 1; i >= 0; i--) p.push(nums[i]);
        for(int i = n - 1; i >= 0; i--){
            while(p.size() > 0 && p.top() <= nums[i]) p.pop();
            if(p.size() == 0){
                nge[i] = -1;
            }
            else{
                nge[i] = p.top();
            }
            p.push(nums[i]);
        }
        return nge;
        
    }
};
      