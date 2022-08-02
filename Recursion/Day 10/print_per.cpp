#include<bits/stdc++.h>  

void allPer(string &str, vector<string> &ans, int ind){
        
        if(ind==str.size())
        {
            ans.push_back(str);
            return;
        }
        
        
        for(int i=ind;i<str.size();i++){
           swap(str[ind],str[i]);
            allPer(str,ans,ind+1);
           swap(str[ind],str[i]);
        }
        
    }

vector<string> findPermutations(string &s) {
     vector<string> ans;

        allPer(s,ans,0);
 
        return ans;
}