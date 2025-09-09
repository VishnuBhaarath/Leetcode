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
         if (!head || left == right) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Move `curr` to the `left`th node
        for (int i = 1; i < left; ++i) {
            prev = curr;
            curr = curr->next;
        }

        // `prev` is node before sublist
        // `curr` is the first node in sublist
        ListNode* sublistPrev = prev;
        ListNode* sublistTail = curr;

        // Reverse the sublist
        ListNode* next = nullptr;
        for (int i = 0; i <= right - left; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Reconnect reversed sublist
        if (sublistPrev) {
            sublistPrev->next = prev;
        } else {
            // If `left == 1`, we reversed from the head
            head = prev;
        }

        sublistTail->next = curr;

        return head;
    }
};