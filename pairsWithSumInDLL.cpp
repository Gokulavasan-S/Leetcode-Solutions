// Link - https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
    public:
      vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
          // code here
          Node* first = head, *last = head;
          vector<pair<int, int>> ans;
          while(last -> next)
          {
              last = last -> next;
          }
          while(first -> data < last -> data)
          {
              int sum = first -> data + last -> data;
              if(sum == target)
              {
                  ans.push_back({first -> data, last -> data});
                  first = first -> next;
                  last = last -> prev;
              }
              else if(sum > target)
              {
                  last = last -> prev;
              }
              else
              {
                  first = first -> next;
              }
          }
          return ans;
      }
  };