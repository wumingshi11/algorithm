struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr) {
            return pHead;
        }
        ListNode* curr = pHead;
        ListNode* next = pHead->next;
        curr->next = nullptr;
        while (next != nullptr)
        {
            ListNode* tmp = next;
            next = next->next;
            tmp->next = curr;
            curr = tmp;
        }
        return curr;

    }
};
