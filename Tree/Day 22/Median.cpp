#include<queue> 


vector<int> findMedian(vector<int> &arr, int n){
	
    priority_queue <int> mx;
 priority_queue <int,vector<int>,greater<int>> mn;

    vector<int> res(n);
    for(int i=0;i<n;i++){
        
        int num = arr[i];
        mx.push(num);
        mn.push(mx.top());
        mx.pop();
        
        if(mn.size()>mx.size()){
            mx.push(mn.top());
            mn.pop();
        }

      if(mn.size()==mx.size()) // even elements
        {
            res[i] = (mn.top() + mx.top())/2;
        }
    else{
        res[i] = mx.top();
    }
    }
    return res;
}
