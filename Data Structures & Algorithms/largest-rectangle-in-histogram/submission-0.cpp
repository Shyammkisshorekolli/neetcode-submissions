class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = n; i >= 0; i--) {

            int currHeight = (i == 0 ? 0 : heights[i - 1]);

            while(!st.empty() &&
                  currHeight < heights[st.top()]) {

                int h = heights[st.top()];
                st.pop();

                int width;

                if(st.empty())
                    width = n - i;
                else
                    width = st.top() - i;

                maxArea = max(maxArea, h * width);
            }

            if(i > 0)
                st.push(i - 1);
        }

        return maxArea;
    }
};