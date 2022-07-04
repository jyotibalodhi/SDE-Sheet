#include<unordered_map>

vector<int> Solution::dNums(vector<int> &arr, int b) {
    
    int n = arr.size();
    if(b >n) return {};
    
    unordered_map<int, int> mp;
    vector<int> ans;
    
    for(int i=0;i<n;i++){
        
        mp[arr[i]]++;
        
        if(i+1 ==b) // first time window complete
        {
            //number of distinct elements = mp.size();
            ans.push_back(mp.size());
        }
        if(i >=b)  // for windows after initial window
        {
            mp[arr[i-b]]--;  // decreing freq of element which are now out of window
            if(mp[arr[i-b]]==0)
                mp.erase(arr[i-b]);
            ans.push_back(mp.size());
        }
    }
    
    return ans;
}
