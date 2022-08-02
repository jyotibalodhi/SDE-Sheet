

void solve(vector<int> nums, int i, vector<int> &ans, int sum){
    
    if(i == nums.size()){
        ans.push_back(sum);
        return;
    }
    
    //take
    solve(nums,i+1,ans, sum + nums[i]);
    //not take
    solve(nums,i+1,ans,sum);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    solve(num,0,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}