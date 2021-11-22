
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, arr;
        stack<int> st;  // used to find Next Greater Elements(NGEs) for array
        
        ListNode* curr = head;
        // store node values into a vector
        while(curr){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        const int n = arr.size();
        
		// now our aim is to find NGE for each element of vector arr
        for(int i=n-1;i>=0;i--){
            if(st.size()==0) res.push_back(0);

            else if(st.size()>0 && arr[i]<st.top())
              res.push_back(st.top());

            else if(st.size()>0 && arr[i]>=st.top()){
               while(st.size()>0 && st.top()<=arr[i]) 
                 st.pop();

               if(st.size()==0) res.push_back(0);
               else res.push_back(st.top());
            }  
            st.push(arr[i]);
        }
        
        reverse(res.begin(),res.end());  // NGEs are found in reverse order initially
        return res;      
    }
};