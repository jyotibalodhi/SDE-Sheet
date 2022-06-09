#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &inter)
{
    sort(inter.begin(),inter.end());
    
    vector<vector<int>> ans;
    
    for(int i=0;i<inter.size();i++){
        vector<int> curr = inter[i];
        
        if(ans.size()==0){
            ans.push_back(curr);
            continue;
        }
        
        vector<int> temp = ans.back();
        ans.pop_back();
        
        if(temp[1] >= curr[0]){
            temp[1] = max(temp[1], curr[1]);
            ans.push_back(temp);
        }
        else{
            ans.push_back(temp);
            ans.push_back(curr);
        }
        
    }
    
    
    return ans;
}
