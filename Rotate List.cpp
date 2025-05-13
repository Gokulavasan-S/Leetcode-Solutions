//link - https://leetcode.com/problems/rotate-list/description/

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
        ListNode* rotateRight(ListNode* head, int k) {
            int len = 1;
            if(! head)
            {
                return head;
            }
            ListNode* curr = head, *temp = head, *dummy = head;
            while(curr -> next)
            {
                curr = curr -> next;
                len ++;
            }
            k = k % len;
            if(k == 0)
            {
                return head;
            }
            int red_len = len - k;
            for(int i = 1; i < red_len; i++)
            {
                temp = temp -> next;
            }
            curr -> next = head;
            head = temp -> next;
            temp -> next = nullptr;
            return head;
        }
    };