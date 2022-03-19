// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
   {
       // code here
       Node*current1=first,*current2=second,*prev1=NULL,*prev2=NULL,*next1=NULL,*next2=NULL;
       int size1=0,size2=0;
       while(current1!=NULL)
       {
           next1=current1->next;
           current1->next=prev1;
           prev1=current1;
           current1=next1;
           size1++;
       }
       first=prev1;
       while(current2!=NULL)
       {
           next2=current2->next;
           current2->next=prev2;
           prev2=current2;
           current2=next2;
           size2++;
       }
       second=prev2;
       int size;
       
       Node*temp1=first,*temp2=second;
       int carry=0,a,i=0;
       if(size2>size1)
       {
           size1=size2;
       }
       long long int arr[size1];
       while(temp1!=NULL && temp2!=NULL)
       {
           a=temp1->data+temp2->data+carry;
           arr[i++]=a%10;
           carry=a/10;
           temp1=temp1->next;
           temp2=temp2->next;
       }
       while(temp1!=NULL)
       {
           a=temp1->data+carry;
           arr[i++]=a%10;
           carry=a/10;
           temp1=temp1->next;
       }
       while(temp2!=NULL)
       {
           a=temp2->data+carry;
           arr[i++]=a%10;
           carry=a/10;
           temp2=temp2->next;
       }
       if(carry>0)
       {
           arr[i++]=carry;
       }
       reverse(arr,arr+i);
       Node*head=NULL,*temp=head;
       for(int i1=0;i1<i;i1++)
       {
          Node*newnode=new Node(arr[i1]);
          if(head==NULL)
          {
              head=newnode;
              temp=head;
          }
          else{
              temp->next=newnode;
              temp=newnode;
          }
       }
       return head;
   }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends