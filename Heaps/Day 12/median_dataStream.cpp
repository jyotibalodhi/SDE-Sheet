#include<bits/stdc++.h>

void findMedian(int *arr, int n)
{
    
    priority_queue <int> mx;
    priority_queue <int,vector<int>,greater<int>> mn;
    
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
                cout<<((mx.top()+mn.top())/2);
            }
           else
            cout<<mx.top();
        cout<<" ";
    }
    return;
}