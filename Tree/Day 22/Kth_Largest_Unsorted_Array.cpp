int kthLargest(vector<int>& nums, int n, int k)
{
        nth_element(nums.begin(),nums.end()-k,nums.end());
        return nums[n-k];
}