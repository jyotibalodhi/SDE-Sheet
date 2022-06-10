#include<stack>
class minStack
{
    stack<pair<int,int>> stk;
	public:
		
		// Constructor
		minStack() 
		{ 
			
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int val)
		{
			  int mini;
        if(stk.empty()){
            mini=val;
        }
        else{
            mini = min(stk.top().second,val);
        }
        
        stk.push({val,mini});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(!stk.empty())
             {
                int val = stk.top().first;
                 stk.pop();
                 return val;
             }
            
            return -1;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
		   if(!stk.empty()) return stk.top().first;
                return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			  if(!stk.empty()) return stk.top().second;
                return -1;
		}
};