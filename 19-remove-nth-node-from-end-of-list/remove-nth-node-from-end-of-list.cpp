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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* curr = head , *prev= NULL;
    int length = 0;

    if (head == NULL)
         return NULL;

        while (curr != NULL) {
            length++;
            curr = curr->next;
        }

        int ith = length - n;

        if (ith == 0) {
            curr = head;
            head = head->next;
            delete curr;
            return head;
        }
        curr = head;
        prev = NULL;
        for (int i = 0; i < ith; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};
