// Link - https://leetcode.com/problems/merge-in-between-linked-lists/

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
        ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
            ListNode* second_last = list2, *first = list1;
            while(second_last -> next)
            {
                second_last = second_last -> next;
            }
            for(int i = 0; i < a - 1; i++)
            {
                first = first -> next;
            }
            ListNode* sec = first;
            for(int i = a; i <= b; i++)
            {
                sec = sec -> next;
            }
                first -> next = list2;
                second_last -> next = sec -> next;
                sec -> next = NULL;
            return list1;
        }
    };