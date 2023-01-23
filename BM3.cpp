#include<iostream>
struct ListNode {
	int val;
	struct ListNode *next;
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        ListNode *endnode = nullptr , *startnode = head;
        ListNode *last_endnode = nullptr, *next_startnode = nullptr;
        ListNode *curr_node = head, *next_node = nullptr;
        
        int count = 0;
        head = nullptr;
        while (curr_node != nullptr)
        {
            /* code */
            count++;
            if (count == k) {
                count = 0;
                next_startnode = curr_node->next;
                if (head == nullptr) {
                    head = curr_node;
                } else {
                    last_endnode->next = curr_node;
                }
                next_node = startnode->next;
                curr_node = startnode;
                for (int i = 0; i < k - 1; i++) {
                    ListNode* tmp = next_node;
                    next_node = next_node->next;
                    tmp->next = curr_node;
                    curr_node = tmp;
                }
                
                curr_node = last_endnode = startnode;
                curr_node->next = next_startnode;
                startnode = next_startnode;
                
            }
            curr_node = curr_node->next;
        }

        return head == nullptr ? startnode : head;
      }
};

ListNode* genList(int* vals, int size) {
    ListNode *head = nullptr, *curr = nullptr;
    for (int i =0; i < size; i++) {
        if (head == nullptr) {
            head = new ListNode;
            curr = head;
        } else {
            curr->next = new ListNode;
            curr = curr->next;
        }
        curr->val = vals[i];
    }
    return head;

}

int main(int argc, char const *argv[])
{
    int vals[] = {0,1,2,3,4};
    ListNode* head = genList(vals, 5);
    Solution s;
    s.reverseKGroup(head, 2);
    std::cout << "finish" << std::endl;
    return 0;
}
