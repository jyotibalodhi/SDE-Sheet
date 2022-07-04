#include<queue>

class Kthlargest {
    vector<int> nums;
    int kth;
    priority_queue<int, vector<int>, greater<int>> pq;
    
public:
    Kthlargest(int k, vector<int> &arr) {
       nums = arr;
       kth = k;
        for(int i =0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }

    void add(int num) {
        nums.push_back(num);
        pq.push(num);
        if(pq.size()> kth) pq.pop();
        return;
    }

    int getKthLargest() {
       return pq.top();
    }

};