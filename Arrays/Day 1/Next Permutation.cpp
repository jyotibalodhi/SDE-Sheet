#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &per, int n)
{
   int ind1=-1;
    int ind2=-1;
    
    for(int i=n-2;i>=0;i--){
        if(per[i]<per[i+1]){
            ind1=i;
            break;
        }
    }
    
    if(ind1 <0) {
        reverse(per.begin(),per.end());
        return per;
    }
    
    for(int i=n-1;i>ind1;i--){
        if(per[i]>per[ind1]){
            ind2= i;
            break;
        }
    }
    
    swap(per[ind1],per[ind2]);
    reverse(per.begin()+ind1+1,per.end());
    
    return per;
}