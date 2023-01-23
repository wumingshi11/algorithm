struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode *qNode = head;
        ListNode *sNode = new ListNode(0);
        sNode->next = head;
        head = sNode;
        while (qNode->next != nullptr) {
           n--;
           qNode = qNode->next;
           if (n <= 0) {
               sNode = sNode->next;
           }
        }
        
        sNode->next = sNode->next->next;
        
        return head->next;
    }
};