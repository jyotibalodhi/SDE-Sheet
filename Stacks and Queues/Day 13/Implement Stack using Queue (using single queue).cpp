#include<queue>

class Stack {
	queue<int> q;
    int size=0;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return (size==0);
    }

    void push(int element) {
        q.push(element);
        size++;
    }

    int pop() {
        if(size==0) return -1;
        
        int k=size-1;
        int val=-1;
        
        while(k--){
            val = q.front();
            q.pop();
            q.push(val);
        }
        
        val=q.front();
        q.pop();
        size--;
        return val;
        
    }

    int top() {
         if(size==0) return -1;
        
        int k=size;
        int val=-1;
        
        while(k--){
            val = q.front();
            q.pop();
            q.push(val);
        }
       
        return val;
    }
};