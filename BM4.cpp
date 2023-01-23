
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        
        ListNode *head = nullptr;
        if (pHead1->val <= pHead2->val) {
           head = pHead1;
           pHead1 = pHead1->next;      
        } else  {
           head = pHead2;
           pHead2 = pHead2->next;
        }
        ListNode *curr = head;

        while (pHead1 != nullptr && pHead2 != nullptr) {
            /* code */
            if (pHead1->val <= pHead2->val) {
                curr->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                curr->next = pHead2;
                pHead2 = pHead2->next;
            }
            curr = curr->next;
        }
        if (pHead1 != nullptr) {
            curr->next = pHead1;
        }
        if (pHead2 != nullptr) {
            curr->next = pHead2;
        }
        return head;
    }
};
