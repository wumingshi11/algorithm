struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr) return pHead;
        auto *nodeOfLoop = find_node(pHead);

        auto *runNode = nodeOfLoop->next;
        int n = 1;
        while (runNode != nodeOfLoop) {
            /* code */
            runNode = runNode->next;
            n++;
        }

        ListNode *bNode = pHead, *aNode = pHead;
        for (int i = 0; i < n; i++) {
            bNode = bNode->next;
        }

        while (bNode != aNode) {
            bNode = bNode->next;
            aNode = aNode->next;
        }
        return bNode;
    }

    ListNode* find_node(ListNode* pHead) {
        ListNode *qnode = pHead, *snode = pHead;
        while (qnode != nullptr)
        {
            /* code */
            qnode = qnode->next;
            if (qnode == nullptr) return nullptr;
            qnode = qnode->next;
            snode = snode->next;
            if (snode == qnode) return snode;
        }
        return nullptr;
        
    }
};