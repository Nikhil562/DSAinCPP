class Solution {
public:
    int trap(std::vector<int>& a) {
        std::vector<int> ngr = nextGreaterRight(a);
        std::vector<int> ngl = nextGreaterLeft(a);
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            if (ngl[i] != -1 && ngr[i] != -1) {
                int temp = std::min(ngl[i], ngr[i]);
                ans += std::abs(temp - a[i]);
            }
        }
        return ans;
    }

    std::vector<int> nextGreaterRight(std::vector<int>& a) {
        int len = a.size();
        std::stack<int> st;
        int max = -1;
        std::vector<int> ans(len);
        for (int i = len - 1; i >= 0; i--) {
            if (st.empty()) {
                ans[i] = -1;
            } else {
                while (!st.empty() && a[st.top()] <= a[i]) {
                    st.pop();
                }
                int temp = st.empty() ? -1 : a[st.top()];
                max = std::max(temp, max);
                ans[i] = max > a[i] ? max : -1;
            }
            st.push(i);
        }
        return ans;
    }

    std::vector<int> nextGreaterLeft(std::vector<int>& a) {
        int len = a.size();
        std::stack<int> st;
        std::vector<int> ans(len);
        int min = -1;
        for (int i = 0; i < len; i++) {
            if (st.empty()) {
                ans[i] = -1;
            } else {
                while (!st.empty() && a[st.top()] <= a[i]) {
                    st.pop();
                }
                int temp = st.empty() ? -1 : a[st.top()];
                min = std::max(temp, min);
                ans[i] = min > a[i] ? min : -1;
            }
            st.push(i);
        }
        return ans;
    }
};
