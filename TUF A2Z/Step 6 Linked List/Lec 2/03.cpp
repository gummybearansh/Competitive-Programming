// insertions in DLL
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *prev;
  Node *next;

  Node(int v) {
    val = v;
    next = nullptr;
    prev = nullptr;
  }
};

Node *insertAtK(Node *head, int k) {
  // 1. Handle insertion at the head (k = 1)
  if (k == 1) {
    Node *newNode = new Node(100);
    newNode->next = head;
    
    // Only update head->prev if the list isn't empty
    if (head != nullptr) {
      head->prev = newNode;
    }
    return newNode; // The new node becomes the new head
  }

  int count = 1;
  Node *temp = head;

  // 2. Traverse the list, checking for out-of-bounds AND incrementing count
  while (temp != nullptr && count < k - 1) {
    temp = temp->next;
    count++; // FIXED: Increment the counter!
  }

  // 3. Check if k is greater than the size of the list + 1
  if (temp == nullptr) {
    // k is out of bounds. You can return head, print an error, or throw an exception.
    return head; 
  }

  // 4. Perform the insertion
  Node *nextNode = temp->next;
  Node *newNode = new Node(100);

  // Link newNode to its surroundings
  newNode->prev = temp;
  newNode->next = nextNode; // Set this unconditionally
  
  // Link surroundings back to newNode
  temp->next = newNode;
  if (nextNode != nullptr) {
    nextNode->prev = newNode;
  }

  return head; // The head remains unchanged
}

Node *makeDLL(int n) {
  int val;
  cin >> val;
  Node *head = new Node(val);
  Node *mover = head;
  for (int i = 1; i < n; i++) {
    cin >> val;
    Node *temp = new Node(val);
    mover->next = temp;
    temp->prev = mover;

    mover = temp;
  }

  return head;
}

void printDLL(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->val << ' ';
    temp = temp->next;
  }
  cout << '\n';
}

int main() {
  int n;
  cin >> n;
  Node *head = makeDLL(n);
  printDLL(head);
  head = insertAtK(head, 4);
  printDLL(head);
}
