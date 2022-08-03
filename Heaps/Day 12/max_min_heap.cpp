vector<int> minHeap(int n, vector<vector<int>>& q) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    vector<int> ans;
    
    for(int i=0;i<n;i++){
        if(q[i].size()==2) //insert operation
        {
            pq.push(q[i][1]);
        }
        else{             // return min element and remove it from heap
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    return ans;
}
