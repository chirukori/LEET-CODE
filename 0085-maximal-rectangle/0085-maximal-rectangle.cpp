class Solution {
public:
 int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
             
            int currHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left - 1;
                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        int maxArea=0;
        vector<int> height(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if(matrix[i][j]=='1'){
                     height[j]+=1;
                }
                else{
                    height[j]=0;
                }
            }
        int area=largestRectangleArea(height);
        maxArea=max(area,maxArea);
    }
    return maxArea;
    }
};