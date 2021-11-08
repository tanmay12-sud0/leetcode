class FrontMiddleBackQueue {
public:
    vector<int> vec;
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        vec.insert(vec.begin(),val);
    }
    
    void pushMiddle(int val) {
        vec.insert(vec.begin()+vec.size()/2,val);
    }
    
    void pushBack(int val) {
        vec.push_back(val);
    }
    
    int popFront() {
        if(vec.size() == 0)
            return -1;
        int value = vec[0];
        vec.erase(vec.begin());
        return value;
    }
    
    int popMiddle() {
        if(vec.size() == 0)
            return -1;
        int value = vec[(vec.size()-1)/2];
        vec.erase(vec.begin()+(vec.size()-1)/2);
        return value;
    }
    int popBack() {
        if(vec.size() == 0)
            return -1;
        int value = vec[vec.size() -1];
        vec.pop_back();
        return value; 
    }
};



// class FrontMiddleBackQueue {
// public:
//     list<int>l;
//     FrontMiddleBackQueue() {
        
//     }
    
//     void pushFront(int val) {
//         l.push_front(val);
//         return;
//     }
    
//     void pushMiddle(int val) {
//         auto it = l.begin();
//         int len = l.size();
//         advance(it, (len/2)-1);
//         l.insert(it, val);
//         return;
//     }
    
//     void pushBack(int val) {
//         l.push_back(val);
//         return;
//     }
    
//     int popFront() {
//         if(l.empty()){
//             return -1;
//         }
//         int t = l.front();
//         l.pop_front();
//         return t;
//     }
    
//     int popMiddle() {
//         if(!l.empty()){
//             auto it = l.begin();
//             int len = l.size();
//             advance(it, (len/2)-1);
//             int t = *it;
//             l.erase(it);
//             return t;
//         }
//             return -1;
//     }
    
//     int popBack() {
//         if(!l.empty()){
//             int t = l.back();
//             l.pop_back();
//             return t;
//         }
//         return -1;
//     }
// };

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */