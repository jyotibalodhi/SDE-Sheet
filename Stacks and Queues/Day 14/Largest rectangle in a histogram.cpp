#include<stack>

int largestRectangle(vector < int > & h) {
     
      stack < int > st;
      int maxA = 0;
      int n = h.size();
        
      for (int i = 0; i <= n; i++) {
          
        while (!st.empty() && (i == n || h[st.top()] >= h[i])) {
          int height = h[st.top()];
          st.pop();
          int width;
            
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
            
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
        
        
      return maxA;
 }