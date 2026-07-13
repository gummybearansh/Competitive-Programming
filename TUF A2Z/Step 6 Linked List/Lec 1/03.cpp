// insertions into LL
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  // constructor with only val
  Node(int d) {
    data = d;
    next = nullptr;
  }

  // constructor with next pointer
  Node(int d, Node *n) {
    data = d;
    next = n;
  }
};

// insertion at kth position
Node *insertAtK(Node *head, int k, int val) {
  if (head == NULL)
    return head;

  // insert at 1st position = insert at head
  if (k == 1) {
    Node *newHead = new Node(val);
    newHead->next = head;
    return newHead;
  }

  int count = 1;
  // i'll find the node at the k-1 position
  Node *prev = head;
  while (count < k - 1) {
    count++;
    prev = prev->next;
  }

  Node *newNode = new Node(val);

  // so now prev points to the Node just previous to our target insertion
  // if this is the last node -> we just point it to our new node
  if (prev->next == NULL)
    prev->next = newNode;

  // otherwise
  Node *nextNode = prev->next;
  prev->next = newNode;
  newNode->next = nextNode;

  return head;
}

// insertion at head (1st node)
Node *insertAtHead(Node *head, int val) {
  // basically create a new node -> make this point to the existing head -> return the new node as the new head
  Node *newHead = new Node(val);
  newHead->next = head;
  return newHead;
}

// insertion at tail (last node)
Node *insertAtTail(Node *head, int val) {
  // iterate to the last node of LL, add the new node there
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  Node *newTail = new Node(val);
  // we're at last node now
  // make the last node point to this new tail
  temp->next = newTail;
  return head;
}

Node *arrayToLL(vector<int> &v) {
  int n = v.size();
  Node *head = new Node(v[0]);
  Node *it = head;
  for (int i = 1; i < n; i++) {
    Node *temp = new Node(v[i]);
    it->next = temp;
    it = it->next;
  }
  return head;
}

void printLL(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << ' ';
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

  Node *head = arrayToLL(v);
  head = insertAtHead(head, 10);
  head = insertAtTail(head, 11);
  printLL(head);
  head = insertAtK(head, 4, 200);
  printLL(head);
}
