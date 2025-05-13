/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
           if(!head || k <= 1)
           {
            return head;
           }
           ListNode *dummy = new ListNode(0);
           dummy -> next = head;
           ListNode *ptr = dummy;
    
           while(ptr -> next)
           {
            ListNode* travel = ptr;
            for(int i = 0; i < k; i++)
            {
                if(travel)
                {
                    travel = travel -> next;
                }
                else
                {
                    break;
                }
            }
            if(!travel)
            {
                break;
            }
    
            pair<ListNode*, ListNode*> rev = reverseLinkedList(ptr -> next, k);
            ListNode *prev = rev.first, *curr = rev.second;
    
            ListNode* revLastNode = ptr -> next;
            ptr -> next = prev;
            revLastNode -> next = curr;
            ptr = revLastNode;
           }
           return dummy -> next;
        }
    
    private:
        pair<ListNode*, ListNode*> reverseLinkedList(ListNode* head, int k) {
            ListNode* previous = nullptr;
            ListNode* current = head;
            ListNode* next = nullptr;
    
            for (int i = 0; i < k; i++) {
                // Temporarily store the next node
                next = current->next;
                // Reverse the current node
                current->next = previous;
                // Before we move to the next node, point previous to the current
                // node
                previous = current;
                // Move to the next node
                current = next;
            }
    
            // Return the new head and the next pointer for further operations
            return {previous, current};
    
        }
    };