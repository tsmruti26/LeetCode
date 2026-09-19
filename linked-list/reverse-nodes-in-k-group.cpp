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
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;

        while (true) {
            // Check if there are at least k nodes ahead
            ListNode* cur = pre;
            for (int i = 0; i < k; ++i) {
                cur = cur->next;
                if (!cur) return dummy.next;  // fewer than k nodes left
            }

            // cur is now the k-th node of the current group
            ListNode* groupStart = pre->next;     // first node of group
            ListNode* afterGroup = cur->next;     // node after group

            // Reverse the group [groupStart ... cur]
            ListNode* prev = nullptr;
            ListNode* curr = groupStart;
            while (curr != afterGroup) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }
            // prev is new head of reversed group,
            // groupStart is now the tail of reversed group

            // Connect previous part to reversed group
            pre->next = prev;
            // Connect tail of reversed group to the rest
            groupStart->next = afterGroup;

            // Move pre to the tail of this reversed group
            pre = groupStart;
        }
    }
};