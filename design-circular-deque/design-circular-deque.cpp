class MyCircularDeque {
public:
    list<int>l;
    int s;
    MyCircularDeque(int k) {
          s  = k;  
    }
    
    bool insertFront(int value) {
        if(l.size()<s){
            l.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(l.size()<s){
            l.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(l.size()>0){
            l.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(l.size()>0){
            l.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(l.size()>0){
            return l.front();
        }
        return -1;
    }
    
    int getRear() {
        if(l.size()>0){
            return l.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return l.size()==0;
    }
    
    bool isFull() {
        return l.size()==s;
    }
};

