class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> right(n);
        vector<int> left(n);
        stack<int> stk;

        // Next Smaller Element to Right
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            right[stk.top()] = n;
            stk.pop();
        }

        // Next Smaller Element to Left
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            left[stk.top()] = -1;
            stk.pop();
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }

        return ans;
    }
};
