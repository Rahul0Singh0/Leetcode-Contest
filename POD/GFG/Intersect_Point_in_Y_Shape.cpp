// https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        unordered_set<Node*> s;
        Node *t = head1;
        while(t != nullptr) {
            s.insert(t);
            t = t->next;
        }
        t = head2;
        while(t != nullptr) {
            if(s.count(t)) {
                return t->data;
            }
            t = t->next;
        }
        return -1;
    }
};