#include<bits/stdc++.h>

bool static cmp(pair<int,int> x, pair<int,int> y){
    //sort according to value/weight
    
    double r1 = (double)x.second/(double)x.first;
    double r2 = (double)y.second/(double)y.first;
    
    return r1 > r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    
    sort(items.begin(),items.end(),cmp);
    
    int curr=0;   //curr weight
    double value = 0.0;
    for(int i=0;i<n;i++){
        if(curr + items[i].first <= w){
            value += items[i].second;
            curr += items[i].first;
        }
        else{
            double diff = w - curr;   //remaining weight of knapsack
            double val = (double)items[i].second/(double)items[i].first;
            value += val*diff;
            break;
        }
    }
    return value;
    
}