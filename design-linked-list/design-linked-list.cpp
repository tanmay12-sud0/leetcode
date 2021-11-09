class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val=val;
        next=NULL;
    }
};

class MyLinkedList {
public:
    
    int size=0;
    Node* head=new Node(0);
    MyLinkedList() {

    }
    
    
    int get(int index) {
        if(index>=size) return -1;
        Node* temp=head->next;
        for(int i=0;i<index;i++) temp=temp->next;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* temp=head->next;
        head->next=new Node(val);
        head->next->next=temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=new Node(val);
        temp->next->next=temp1;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=temp1->next;
        temp1->next=NULL;
        size--;
        delete temp1;
    }
};
















// class MyLinkedList {
// public:
    
//     class Node{
// public:
// 	int data;
// 	Node* next;

// 	Node(int d){
// 		data = d;
// 		next = NULL;
// 	}
// };
//     Node * head = NULL;
    
//     int lenght(Node* head){
// 	Node* temp = head;
// 	int count = 0;
// 	while(temp!= NULL){
// 		count++;
// 		temp = temp->next;
// 	}
// 	return count;
//     }
    
//     MyLinkedList() {
        
//     }
    
//     int get(int index) {
//         Node* temp = head;
//         int count = 0;
//         while(count < index-1){
// 		temp = temp->next;
// 	}
// 	return temp->val;
//     }
    
//     void addAtHead(int val) {
//         if(head == NULL){
// 		head = new Node(val);
// 		return;
// 	    }

// 	    Node* temp = new Node(val);
// 	    temp->next = head;
// 	    head = temp;
// 	    return;
//     }
    
//     void addAtTail(int val) {
//         if(head == NULL){
// 		addAtHead(head, val);
// 		return;
// 	    }
// 	    Node* temp = head;
// 	    while(temp->next!= NULL){
// 		    temp = temp->next;
// 	    }
// 	    Node* n = new Node(val);
// 	    temp->next = n;
// 	    return;
//     }
    
//     void addAtIndex(int index, int val) {
//         if(head == NULL){
// 		addAtHead(head, val);
// 		return;
// 	}

// 	if(pos > lenght(head)){
// 		addAtTail(head, val);
// 		return;
// 	}
// 	Node* temp = head;
// 	int count = 1;
// 	while(count < pos-1){
// 		temp = temp->next;
// 		count++;
// 	}
// 	Node* n = new Node(val);
// 	n->next = temp->next;
// 	temp->next = n;
// 	return;
//     }
    
//     void deleteAtIndex(int index) {
        
//     }
// };

