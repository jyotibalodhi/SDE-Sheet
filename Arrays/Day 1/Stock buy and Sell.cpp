#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices){
    int pro=0;
    int mini = INT_MAX;
    
    for(int i=0;i<prices.size();i++){
        mini = min(mini, prices[i]);
        pro = max(pro, prices[i]-mini);
    }
    
    return pro;
}