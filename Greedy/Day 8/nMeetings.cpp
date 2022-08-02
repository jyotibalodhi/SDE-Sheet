#include<bits/stdc++.h>


bool static cmp(vector<int> &m1, vector<int> &m2){
    if(m1[1] < m2[1]) return true;
    else if(m1[1] > m2[1]) return false;
    else if(m1[2] < m2[2]) return true;
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    
    int n = start.size();
    vector<vector<int>> v(n, vector<int>(3,0));
    
    for(int i=0;i<n;i++)
    {
        v[i][0] = start[i];
        v[i][1]= end[i];
        v[i][2] =i+1;  //position of meeting
    }
    
    sort(v.begin(),v.end(),cmp);
    
    int limit = v[0][1];  // end time of first meeting
    vector<int> ans;
    ans.push_back(v[0][2]);  //first meeting can always happen
    
    for(int i=1;i<n;i++){
        if(v[i][0] > limit){
            ans.push_back(v[i][2]);
            limit = v[i][1];
        }
    }
    
    return ans;
    
}