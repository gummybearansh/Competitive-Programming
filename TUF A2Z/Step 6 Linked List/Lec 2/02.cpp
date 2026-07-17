// Deletions in DLL
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *prev;

  Node(int v) {
    val = v;
    next = nullptr;
    prev = nullptr;
  }
};

// delete "Kth" node
Node *deleteAtK(Node *head, int k) {
  // deletion of head
  if (k == 1) {
    Node *newHead = head->next;
    // if more than 1 node in the DLL - sever the backward tie
    if (newHead != nullptr) {
      newHead->prev = nullptr;
    }
    delete head;
    return newHead;
  }

  // traverse to k-1 node
  int counter = 1;
  Node *temp = head;
  while (temp != nullptr && counter < k - 1) {
    temp = temp->next;
    counter++;
  }

  Node *kthNode = temp->next;
  Node *before = temp;
  Node *after = kthNode->next;

  // binding logic (handles tail as well)
  before->next = after;
  if (after != nullptr) {
    after->prev = before;
  }

  delete kthNode;
  return head;
}

Node *arrayToDLL(vector<int> &v) {
  int n = v.size();
  Node *head = new Node(v[0]);
  Node *it = head;
  for (int i = 1; i < n; i++) {
    Node *temp = new Node(v[i]);
    it->next = temp;
    temp->prev = it;

    it = temp;
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
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  Node *head = arrayToDLL(v);
  printDLL(head);
  head = deleteAtK(head, 4);
  printDLL(head);
}
