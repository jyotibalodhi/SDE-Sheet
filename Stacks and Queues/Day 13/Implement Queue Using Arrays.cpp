#include<algorithm>


class Queue {
public:
    
    vector<int> arr;
    int size=0;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (size==0);    
    }

    void enqueue(int data) {
        arr.push_back(data);
        size++;
    }

    int dequeue() {
        if(size ==0) return -1;
        
        reverse(arr.begin(),arr.end());
        int val =arr[size-1];
        arr.resize(size-1);
        reverse(arr.begin(),arr.end());
        size--;
        return val;
    }

    int front() {
          if(size ==0) return -1;

        return arr[0];
    }
};