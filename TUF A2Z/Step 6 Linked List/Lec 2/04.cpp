// reverse a dll
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

Node* reverseDLL(Node* head){
  // our head becomes the new tail 
  // just iterate till the end - reversing the links 
  // return the tail as the new head
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
}
