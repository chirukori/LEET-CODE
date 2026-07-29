class Solution {
public:
    const int MOD = 1000000007;

    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prev;
    }

    vector<int> nextSmallerOrEqual(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return next;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> prev = prevSmaller(arr);
        vector<int> next = nextSmallerOrEqual(arr);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = (ans + (1LL * arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return (int)ans;
    }
};