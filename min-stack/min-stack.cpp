class MinStack {
    stack<int> data;
    stack<int> minData;
public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
      if (minData.size() == 0 || val <= minData.top()) 
        minData.push(val);
        
    }
    
    void pop() {
        int val = data.top();
            data.pop();
        if (val == minData.top()) 
          minData.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minData.top();
    }
};
















// class MinStack {
//     stack<int> s1;
//     stack<int> s2;
    
// public:

//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(s1.empty()){
//             s1.push(val);
            
//         }else{
//             while(s1.top() < val){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(val);
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//             }
//         }
        
//     }
    
//     void pop() {
//         s1.pop();
       
//     }
    
//     int top() {
//         return s1.top();
//     }
    
//     int getMin() {
//         return s1.top();
//     }
// };
