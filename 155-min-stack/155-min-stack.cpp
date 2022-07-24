class MinStack {
public:
    stack<int>s;
    stack<int>min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min_stack.empty()){
            min_stack.push(val);
        }else{
            if(min_stack.top() > val){
                min_stack.push(val);
            }else{
                min_stack.push(min_stack.top());
            }
        }
        return;
    }
    
    void pop() {
        s.pop();
        min_stack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};