



struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x = -1, ListNode* ptr = nullptr) : val(x), next(ptr) {}
};


class Soluiton {

public:
	ListNode* swapPairs(ListNode* head) {
		
		// 创建哑节点
		ListNode* dummyHead = new ListNode();

		// 接上输入的链表
		dummyHead->next = head;

		ListNode* temp = dummyHead;

		while (temp->next != nullptr && temp->next->next != nullptr) {
			ListNode* node1 = temp->next;
			ListNode* node2 = temp->next->next;
			temp->next = node2;
			node1->next = node2->next;
			node2->next = node1;
			temp = node1;
		
		
		}
		ListNode* ans = dummyHead->next;
		delete dummyHead;
		return ans;
	}
};