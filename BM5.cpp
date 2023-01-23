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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = nullptr;
        int n = find_min(lists);
        if (n == -1) return nullptr;
        head = lists[n];
        lists[n] = lists[n]->next;
        ListNode *curr = head;
        while (n != -1) {
            /* code */
            n = find_min(lists);
            if (n == -1) break;
            curr->next = lists[n];
            lists[n] = lists[n]->next;
            curr = curr->next;
        }
        return head;  
    }
private:
    int find_min(vector<ListNode *> &lists) {
        int n = -1, min = 10001;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) { 
                if (lists[i]->val < min) {
                    min = lists[i]->val;
                    n = i;
                }
            }
        }
        return n;
    }
};