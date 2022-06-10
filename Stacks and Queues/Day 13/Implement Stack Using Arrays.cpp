// Stack class.
class Stack {
    
public:
    int limit;
    vector<int> arr;
    int size=0;
    Stack(int capacity) {
        limit = capacity;
    }

    void push(int num) {
        if(size <= limit){
            arr.push_back(num);
            size++;
        }
        
        return;
    }

    int pop() {
        int val =-1;
       if(size >0){
           val = arr[size-1];
           arr.resize(size-1);
           size--;
       }
        
        return val;
    }
    
    int top() {
         int val =-1;
       if(size >0){
           val = arr[size-1];
       }
        
        return val;
    }
    
    int isEmpty() {
        return (size==0);
    }
    
    int isFull() {
        return (size==limit);
    }
    
};