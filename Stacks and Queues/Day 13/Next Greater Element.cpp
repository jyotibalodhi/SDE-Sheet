#include<stack>

vector<int> nextGreater(vector<int> &nums, int n) {
    
    vector<int> res(n,-1);
    stack<int> st;
    
   for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
          st.pop();
        }

        if (!st.empty() && st.top()>nums[i]) {
          res[i] = st.top();
        }
        st.push(nums[i]);
      }
      return res;

}