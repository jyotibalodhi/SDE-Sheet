#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> res(n,-1);
    stack<int> stk;
    
    
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && stk.top()>= arr[i])
            stk.pop();
        
        if(!stk.empty() && stk.top()<arr[i])
            res[i]=stk.top();
        
        stk.push(arr[i]);
    }
    
    return res;
}