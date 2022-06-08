#include<stack>

class Queue {
    // Define the data members(if any) here.
    
    stack<int> stk1;
    stack<int> stk2;
    
    int size=0;
    int top=-1;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        stk1.push(val);
        size++;
        if(size==1)
            top= stk1.top();
    }

    int deQueue() {
        if(size==0){
            top=-1;
            return -1;
        }
        
        if(stk1.size()==1){
            int val=stk1.top();
            stk1.pop();
            size--;
            top=-1;
            return val;
        }
        
        while(stk1.size() >1){
            int val = stk1.top();
            stk1.pop();
            stk2.push(val);
        }
        
        size--;
        int val= stk1.top();
        stk1.pop();
        
        top=stk2.top();
        
        while(stk2.size()){
            int val = stk2.top();
            stk2.pop();
            stk1.push(val);
        }
        
        return val;
    }

    int peek() {
        return top;
    }

    bool isEmpty() {
        return (size==0);
    }
};