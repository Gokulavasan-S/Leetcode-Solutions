//link - https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
    public:
      void deleteAllOccurOfX(struct Node** head_ref, int x) {
          // Write your code here
          Node *head = *head_ref, *curr = head;
          while(curr)
          {
              if(curr -> data == x)
              {
                  if(curr -> prev)
                      curr -> prev -> next = curr -> next;
                  else 
                      *head_ref = curr -> next;
                  if(curr -> next)
                      curr -> next -> prev = curr -> prev;
              }
              
                  curr = curr -> next;
          }
      }
  };
  