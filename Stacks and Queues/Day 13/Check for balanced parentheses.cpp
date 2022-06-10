#include<stack>

bool isValidParenthesis(string expression)
{
    stack<char> stk;
    
    for(char s: expression){
        if(s=='('  || s== '[' || s=='{'){
            stk.push(s);
        }
        else{
            if(s == ')'){
                if(!stk.empty() && stk.top() == '('){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else  if(s == ']'){
                if(!stk.empty() && stk.top() == '['){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else  if(s == '}'){
                if( !stk.empty() && stk.top() == '{'){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    
    if(stk.empty()) return true;
    
    return false;
}