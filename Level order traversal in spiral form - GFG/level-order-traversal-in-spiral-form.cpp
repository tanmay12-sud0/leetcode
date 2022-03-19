// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends





//Function to return a list containing the level order traversal in spiral form.
// vector<int> findSpiral(Node *root)
// {
//     vector<int>hash;
//     vector<int>tan;
//     if(root==NULL){
//         return hash;
//     }
//     int cnt = 0;
//     queue<Node*>q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         Node* f = q.front();
//         q.pop();
//         cnt++;
//         if(f == NULL){
//             if(cnt%2 == 0){
//                 for(auto x : tan){
//                     hash.push_back(x);
//                 }
//             }else{
//                 for(auto x : tan){
//                     hash.push_back(x);
//                 }
//             }
//             if(!q.empty()){
//                 q.push(NULL);
//                 tan.clear();
//             }
//         }
//         else{
//             tan.push_back(f->data);
//         if(f->left){
//             q.push(f->left);
//         }
//         if(f->right){
//             q.push(f->right);
//         }
//         }
        
//     }
//     return hash;
// }

vector<int> findSpiral(Node *root)
{
      //Your code here
      vector<int> ans;
      stack<Node*> currLevel;
      stack<Node*> nextLevel;
      bool leftTOright=0;
      currLevel.push(root);
      while(!currLevel.empty()){
        Node* temp=currLevel.top();
        currLevel.pop();
        if(temp!=NULL){
            ans.push_back(temp->data);
          if(leftTOright){
            if(temp->left!=NULL){
              nextLevel.push(temp->left);
            }
            if(temp->right!=NULL){
              nextLevel.push(temp->right);
            }
          }
          else{
            if(temp->right!=NULL){
              nextLevel.push(temp->right);
            }
            if(temp->left!=NULL){
              nextLevel.push(temp->left);
            }
          }
        }
        if(currLevel.empty()){
          leftTOright=!leftTOright;
          swap(currLevel, nextLevel);
        }
      }
      return ans;
}


