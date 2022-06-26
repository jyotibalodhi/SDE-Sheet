#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    //extension of Moore's voting algorithm

    int n1=0,n2=0;
    int c1=0,c2=0;
    
    for(int i=0;i<arr.size();i++){
        if(n1 == arr[i])c1++;
        else if(n2== arr[i]) c2++;
        else if(c1==0){ 
            n1=arr[i];
            c1=1;
        }
        else if(c2==0){ 
            n2= arr[i];
            c2=1;
        }
        else {
            c1--;
            c2--;
        }
    }
    c1=0,c2=0;
    for(int i=0;i<arr.size();i++){
        if(n1 == arr[i]) c1++;
        else if(n2== arr[i]) c2++;
    }
    vector<int> res;
    
    
    if(c1 > arr.size()/3) res.push_back(n1);
    if(c2 > arr.size()/3) res.push_back(n2);
    
    return res;
    
}