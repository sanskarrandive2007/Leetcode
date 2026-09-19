// Q] What is the largest rectangle in a histogram?

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.


// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.


// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

// Solution Of This Question :-

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>nse(n);
        int i;
        for( i = n - 1; i >= 0; i--){
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.size() == 0){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        vector<int>pse(n);
        stack<int>ans;

        for(int i = 0; i < n; i++){
            while(ans.size() > 0 && heights[ans.top()] >= heights[i]){
                ans.pop();
            }
            if(ans.size() == 0){
                pse[i] = -1;
            }
            else{
                pse[i] = ans.top();
            }
            ans.push(i);
        }
        int max1 = 0;
        for(int i = 0; i < n; i++){
            int width = nse[i] - pse[i] - 1;
            int height = heights[i];
            max1 = max(max1, width * height);
        }
        return max1;



        
    }
};