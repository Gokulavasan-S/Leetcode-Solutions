//Link - https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            //Ths is hashmap approach using extra sapce. efficient soln without extra space is below this.
        //     std::unordered_map<Node*, Node*> hashMap;
        //     Node* cur = head;
    
        //     while (cur) {
        //         hashMap[cur] = new Node(cur->val);
        //         cur = cur->next;
        //     }
    
        //     cur = head;
    
        //     while (cur) {
        //         Node* copy = hashMap[cur];
        //         copy->next = hashMap[cur->next];
        //         copy->random = hashMap[cur->random];
        //         cur = cur->next;
        //     }
    
        // return hashMap[head]; 
            Node *temp = head;
    
            while(temp)
            {
                Node* newNode = new Node(temp -> val);
                newNode -> next = temp -> next;
                temp -> next = newNode;
                temp = newNode -> next;
            }
    
            temp = head;
            while(temp)
            {
                if(temp -> random)
                {
                    temp -> next -> random = temp -> random -> next;
                }
                temp = temp -> next -> next;
            }
    
            temp = head;
            Node* dummy1 = new Node(0);
            Node* dummy = dummy1;
            while(temp)
            {
                dummy -> next = temp -> next;
                temp -> next = temp -> next -> next ;
                temp = temp -> next;
                dummy = dummy -> next;
            }
            return dummy1 -> next;
        }
    };