//Flattening a Linked List
//Link - https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1


/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
    private:
      Node *merge(Node *List1, Node* List2)
      {
          Node* dummy = new Node(0);
          Node* res = dummy;
          while(List1 && List2)
          {
              if(List1 -> data <= List2 -> data)
              {
                  res -> bottom = List1;
                  res = List1;
                  List1 = List1 -> bottom;
              }
              else
              {
                  res -> bottom = List2;
                  res = List2;
                  List2 = List2 -> bottom;
              }
              res -> next = NULL;
          }
          if(List1)
              res -> bottom = List1;
          if(List2)
              res -> bottom = List2;
          if(dummy -> bottom)
              dummy -> bottom -> next = NULL;
          return dummy -> bottom;
          
          // The below is recursive implementation.
          /*if(!List1)
              return List2;
          if(!List2)
              return List1;
              
          if(List1 -> data <= List2 -> data)
          {
              List1 -> bottom = merge(List1 -> bottom, List2);
              return List1;
          }
          else
          {
              List2 -> bottom = merge(List1, List2 -> bottom);
              return List2;
          }*/
      }
  
    public:
      // Function which returns the  root of the flattened linked list.
      Node *flatten(Node *root) {
          if(!root || !root -> next)
          {
              return root;
          }
          
          Node *second_root = flatten(root -> next);
          return merge(root, second_root);
      }
  };