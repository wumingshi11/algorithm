#include<vector>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *qhead = head;
        ListNode *shead = head;
        while (qhead != nullptr)
        {
            qhead = qhead->next;
            if (qhead == nullptr) return false;
            qhead = qhead->next;
            shead = shead->next;
            if (qhead == shead) return true;

        };
        return false;
        
    }
};