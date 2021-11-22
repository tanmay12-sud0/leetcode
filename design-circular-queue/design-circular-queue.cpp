class MyCircularQueue {
public:
    list<int>l;
    int size;
    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int value) {
        if(l.size() < size){
            l.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(l.size()){
            l.erase(l.begin());
            return true;
        }
        return false;
    }
    
    int Front() {
        if(l.size()>0){
            return l.front();
        }else{
            return -1;
        }
    }
    
    int Rear() {
        if(l.size()>0){
            return l.back();
        }else{
            return -1;
        }
    }
    
    bool isEmpty() {
        return l.size()==0;
    }
    
    bool isFull() {
        if(l.size() == size){
            return true;
        }
        return false;
    }
};

//  list<int> mylist;
//     int size;
//     /** Initialize your data structure here. Set the size of the queue to be k. */
//     MyCircularQueue(int k) {
//       //  mylist.resize(k);
//         size = k;
//     }
    
//     /** Insert an element into the circular queue. Return true if the operation is successful. */
//     bool enQueue(int value) {
//         if(mylist.size()<size)
//         {
//             mylist.push_back(value);
//             return true;
//         }
//         return false;
//     }
    
//     /** Delete an element from the circular queue. Return true if the operation is successful. */
//     bool deQueue() {
//         if(mylist.size()>0)
//         {
//             mylist.erase(mylist.begin());
//             return true;
//         }
//         return false;
//     }
    
//     /** Get the front item from the queue. */
//     int Front() {
//         if(mylist.size()>0)
//             return mylist.front();
//         return -1;
//     }
    
//     /** Get the last item from the queue. */
//     int Rear() {
//         if(mylist.size()>0)
//             return mylist.back();
//         return -1;
//     }
    
//     /** Checks whether the circular queue is empty or not. */
//     bool isEmpty() {
//         return (mylist.size()==0);
//     }
    
//     /** Checks whether the circular queue is full or not. */
//     bool isFull() {
//         return (mylist.size()== size);
//     }