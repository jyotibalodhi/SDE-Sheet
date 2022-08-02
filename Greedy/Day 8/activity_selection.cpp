#include<bits/stdc++.h>


bool static cmp(vector<int> &m1, vector<int> &m2){
    return m1[1] < m2[1];
}
int maximumActivities(vector<int> &start, vector<int> &end) {
    
    int n = start.size();
    vector<vector<int>> v(n, vector<int>(2,0));
    
    for(int i=0;i<n;i++)
    {
        v[i][0] = start[i];
        v[i][1]= end[i];
    }
    
    sort(v.begin(),v.end(),cmp);
    
    int limit = v[0][1];  // end time of first actvity
    int cnt =1;
    
    for(int i=1;i<n;i++){
        if(v[i][0] >= limit){
           cnt++;
            limit = v[i][1];
        }
    }
    
    return cnt;
}