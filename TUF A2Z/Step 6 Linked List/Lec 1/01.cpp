#include <array>
#include <bits/stdc++.h>
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
int countNodesLL(Node* head){
  Node* temp = head;
  int count = 0;
  while (temp != nullptr){
    count ++;
    temp = temp -> next;
  }
  return count;
}

int main() {
  // y stores the pointer to this newly created node
  // Node *y = new Node(2, nullptr);

  // -> syntax is short for (*y).data (dereference the pointer and access the data)
  // cout << y << ' ' << (*y).data << ' ' << y->next << '\n';

  // code to convert array into LL
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // LL created returned head
  Node *head = arrayToLL(v);

  // print the LL
  printLL(head);

  // count number of nodes in LL
  int count = countNodesLL(head);
  cout << "Count: " << count << '\n';
}
