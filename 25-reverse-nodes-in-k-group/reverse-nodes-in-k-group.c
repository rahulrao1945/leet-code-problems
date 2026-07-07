/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *groupPrev = &dummy;

    while (1) {
        // Find the kth node
        struct ListNode *kth = groupPrev;
        for (int i = 0; i < k && kth; i++) {
            kth = kth->next;
        }

        if (!kth)
            break;

        struct ListNode *groupNext = kth->next;

        // Reverse current group
        struct ListNode *prev = groupNext;
        struct ListNode *curr = groupPrev->next;

        while (curr != groupNext) {
            struct ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Connect reversed group
        struct ListNode *temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }

    return dummy.next;
}