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
    ListNode* reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        stack<ListNode*> stk;
        ListNode* secondHalf = slow->next;
        slow->next = NULL;

        while (secondHalf != NULL) {
            stk.push(secondHalf);
            secondHalf = secondHalf->next;
        }
        ListNode* first = head;
        while (!stk.empty()) {
            ListNode* topNode = stk.top();
            stk.pop();
            ListNode* second = first->next;
            first->next = topNode;
            topNode->next = second;
            first = second;
        }

        return head;
    }
};