// Intro to DLL
#include <array>
#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node representation
class Node {
public:
  int val;
  // stores pointer to both next and previous node
  Node *next;
  Node *prev;

  // constructor with only val
  Node(int v) {
    val = v;
    next = nullptr;
    prev = nullptr;
  }

  // constructor with val and pointers to next and previou
  Node(int v, Node *n, Node *p) {
    val = v;
    next = n;
    prev = p;
  }
};

// returns head of DLL
Node *arrayToDLL(vector<int> &v) {
  int n = v.size();
  if (n < 1)
    return nullptr;

  Node *head = new Node(v[0]);
  // iterator
  Node *it = head;
  for (int i = 1; i < n; i++) {
    Node *temp = new Node(v[i]);
    // attach pointers
    it->next = temp;
    temp->prev = it;

    // move ahead
    it = temp;
  }

  return head;
}

// iterate over DLL and print val
void printDLL(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->val << ' ';
    temp = temp->next;
  }
  cout << '\n';
}

// find tail of DLL
Node *findTail(Node *head) {
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // now temp points to the last Node (it's next is NULL)
  return temp;
}

// print from reverse
void printDLLReverse(Node *tail) {
  Node *temp = tail;
  while (temp != NULL) {
    cout << temp->val << ' ';
    temp = temp->prev;
  }
  cout << '\n';
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  Node *head = arrayToDLL(v);

  printDLL(head);

  Node *tail = findTail(head);
  printDLLReverse(tail);
}
