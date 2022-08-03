#include<bits/stdc++.h>

int longestIncreasingSubsequence(int nums[], int n)
{
        vector<int> ans;
        ans.push_back(nums[0]);
        int idx;
        for(int i=1;i<n;i++){
            idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            if(idx<ans.size())
                ans[idx]=nums[i];
            else
                ans.push_back(nums[i]);
        }
        return ans.size();
}
