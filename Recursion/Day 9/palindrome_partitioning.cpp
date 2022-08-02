#include<bits/stdc++.h>

bool isPallindrome(string str, int e,int s){
    while(s<=e){
        if(str[s] != str[e]) return false;
        s++;
        e--;
    }
    return true;
}

void solve(string &s, vector<vector<string>> &res, int ind, vector<string> str){
    if(ind == s.length()){
        res.push_back(str);
        return;
    }
    
    for(int i=ind;i<s.length();i++){
        if(isPallindrome(s,i,ind)){
            str.push_back(s.substr(ind,i-ind+1));
            solve(s,res,i+1,str);
            str.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
   vector<vector<string>> res;
    solve(s,res,0,{});
    return res;
}