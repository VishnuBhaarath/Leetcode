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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
              // Step 1: Edge case
        if (!head || left == right) return head;

        // Create a dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Reach node at position `left`
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // `start` is the first node to reverse
        ListNode* start = prev->next;
        // `then` is the node after start
        ListNode* then = start->next;

        // Step 3: Reverse nodes from `left` to `right`
        for (int i = 0; i < right - left; i++) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        return dummy->next;
    }
};