// Deleting Nodes in LL
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

class Node {
public:
  int data;
  Node *next; // pointer to the next node (type is Node)

  // initialise using constructor
  Node(int d, Node *n) {
    data = d;
    next = n;
  }

  // constructor to point this node to nullptr
  Node(int d) {
    data = d;
    next = nullptr;
  }
};

// 1. Delete the Head (1st node):
Node *deleteFromHead(Node *head) { // O(1)
  // make sure LL has atleast 1 node
  if (head == NULL)
    return head;
  // basically point the head to the next node
  Node *temp = head;
  head = head->next;
  // make sure to delete the head - no memory leak
  delete temp;
  return head;
}

// 2. Delete the tail of the LL (last node)
Node *deleteTail(Node *head) { // O(N)
  // make sure LL has atleast 2 elements (if 1 - even deleting that would be NULL)
  if (head == NULL || head -> next == nullptr) return NULL;

  Node *it = head;
  // keep moving it over the LL
  while (it != nullptr) {
    Node *nextNode = it->next;
    // if nextNode is the last one -> we'll delete it
    if (nextNode->next == nullptr) {
      delete nextNode;
      it->next = nullptr;
    }
    it = it->next;
  }
  return head;
}

// 3. Delete a node from the LL 
// you're given just a node from the LL 
// you need to delete this node - no access to other previous elements 
Node *deleteNode(Node* node){
  // make this node's value the next node's value 
  // make this node skip the next node
  // delete the next node
  Node* nextNode = node -> next;
  node -> val = nextNode -> val;
  node -
}

// convert array to LL
Node *arrayToLL(vector<int> &v) {
  int n = v.size();
  Node *head = new Node(v[0]);
  Node *mover = head;

  for (int i = 1; i < n; i++) {
    // node for this element
    Node *temp = new Node(v[i]);
    // add the link to this new node
    mover->next = temp;
    // move the mover
    mover = mover->next;
  }
  return head;
}

// traverse LL and print the nodes
void printLL(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << ' ';
    temp = temp->next;
  }
}

// traverse LL and return count
int countNodesLL(Node *head) {
  Node *temp = head;
  int count = 0;
  while (temp != nullptr) {
    count++;
    temp = temp->next;
  }
  return count;
}

int main() {
  // code to convert array into LL
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // LL created returned head
  Node *head = arrayToLL(v);

  // Delete Head of LL
  // head = deleteFromHead(head);

  // Delete Tail of LL
  head = deleteTail(head);
  printLL(head);
}
