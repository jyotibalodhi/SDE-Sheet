#include<stack>

vector<int> maxMinWindow(vector<int> arr, int n) {
     
     stack<int> s;
 

    int left[n+1]; 
    int right[n+1];
    
    //next greater element concept
    for (int i=0; i<n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }
 
    for (int i=0; i<n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
 
        if (!s.empty())
            left[i] = s.top();
 
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = n-1 ; i>=0 ; i-- )
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
 
        if(!s.empty())
            right[i] = s.top();
 
        s.push(i);
    }
 
    vector<int> ans(n+1,INT_MIN);

    for (int i=0; i<n; i++)
    {
        // length of the interval
        int len = right[i] - left[i] - 1;
 
        ans[len] = max(ans[len], arr[i]);
    }

    //for the positions which remain unfilled
    for (int i=n-1; i>=1; i--)
        ans[i] = max(ans[i], ans[i+1]);
 
    
    reverse(ans.begin(),ans.end());
    ans.pop_back();  // as ans[0] is of no use
    reverse(ans.begin(),ans.end());
    
    return ans;
}