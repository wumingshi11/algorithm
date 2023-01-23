struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr) return nullptr;
        
        int n1 = length(pHead1);
        int n2 = length(pHead2);
        int diff = 0;
        if (n1 < n2) {
            ListNode *tmp = pHead1;
            pHead1 = pHead2;
            pHead2 = tmp;
            diff = n2 -n1;
        } else {
            diff = n1 - n2;
        }
        for (int i = 0; i < diff; i++) {
            pHead1 = pHead1->next;
        }
        while (pHead1 != nullptr) {
            /* code */
            if (pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }

        return nullptr;
        
       
        
        
    }

    int length(ListNode *head) {
        int n = 0;
        while (head != nullptr)
        {
            /* code */
            head = head->next;
            n++;
        }
        
    }
};
