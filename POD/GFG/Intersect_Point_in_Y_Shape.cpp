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
    int intersectPoint(Node* head1, Node* head2) {
        int c1=0,c2=0;
        Node *p1=head1,*p2=head2;
        while(p1) c1++, p1=p1->next;
        while(p2) c2++, p2=p2->next;
        p1=head1;
        p2=head2;
        int diff=abs(c1 - c2);
        if(c1 > c2) for(int i = 0; i < diff; i++) p1=p1->next;
        else if(c1 < c2) for(int i = 0; i < diff; i++) p2=p2->next;
        while(p1!=p2) {
            p1=p1->next;
            p2=p2->next;
        }
        if(p1 != nullptr) return p1->data;
        return -1;
    }
};