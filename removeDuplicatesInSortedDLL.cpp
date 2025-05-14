// Link - https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
    public:
  
      Node *removeDuplicates(struct Node *head) {
          // Your code here
          if(!head || !head -> next)
          {
              return head;
          }
          Node *curr = head, *previous = head;
          while(curr)
          {
              if(curr -> data != previous -> data)
              {
                  curr -> prev = previous;
                  previous -> next = curr;
                  previous = curr;
              }
              curr = curr -> next;
          }
          previous -> next = NULL;
          return head;
      }
  };
  