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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* oddPointer = head;
        ListNode* evenHead = head->next;
        ListNode* evenPointer = evenHead;

        while (evenPointer != NULL && evenPointer->next != NULL) {
            oddPointer->next = evenPointer->next;
            oddPointer = oddPointer->next;
            evenPointer->next = oddPointer->next;
            evenPointer = evenPointer->next;
        }
        oddPointer->next = evenHead;

        return head;
    }
};