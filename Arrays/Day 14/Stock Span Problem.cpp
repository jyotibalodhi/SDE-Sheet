#include<stack>

vector<int> findSpans(vector<int> &price) {
    
    int n= price.size();
    
    vector<int> res(n,1);
    stack<int> stk;
    
    for(int i=0;i<n;i++){
        
        while(!stk.empty() && price[stk.top()]<= price[i]){
            res[i] += res[stk.top()];
            stk.pop();
        }
        
        stk.push(i);
    }
    
    return res;
}