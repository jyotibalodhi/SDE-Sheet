#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
   unordered_map<char,int> m;   // to keep check of last position of character
    
    int len=0;
    int l=0,r=0;
    int n= input.length();
    
    while(r<n){
        if(m.find(input[r]) != m.end())  // repeating
        {
            l = max(l, m[input[r]]+1);
        }
        
        m[input[r]] = r;  // updating new index
        len = max(len, r-l+1);
        r++;
    }
    
    return len;
}