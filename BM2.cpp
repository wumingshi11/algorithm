
struct ListNode {
    int val;
 	struct ListNode *next;
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(head == nullptr) return head;
        if(m <= n || m < 0 || n < 0) return head;
        ListNode* startNode = nullptr;
        ListNode* currNode = head;
        ListNode* reNode = nullptr;
        for (int i = 1; i <= n; i++) {
            if (currNode == nullptr) return nullptr;
            if (i < m - 1) {
                currNode = currNode->next;
            } else if (i == m - 1) {
                startNode = currNode;
                currNode = currNode->next;
            } else if (i < n) {
                ListNode* tmp = currNode;
                currNode = currNode->next;
                tmp->next = reNode;
                reNode = tmp; 
            } else if (i == n) {
               ListNode* tmp = currNode;
               currNode = currNode->next; //last
               if (startNode == nullptr) {
                   head->next = currNode;
                   head = tmp;
               } else {
                   startNode->next->next = currNode;
                   startNode->next = tmp;
               }
               tmp->next = reNode;
               
            }  
        } 
        return head;
    }
};