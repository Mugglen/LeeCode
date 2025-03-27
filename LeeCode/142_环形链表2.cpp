#include <iostream>
using namespace std; // NULLҲ��std���




struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}

};


// ����ָ�뷨����ͷ������һ��ָ�룬�������ڵ� Ҳ����һ��ָ�룬
// ������ָ��ÿ��ֻ��һ���ڵ㣬 ��ô��������ָ��������ʱ����� ������ڵĽڵ㡣��
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		// ��������ָ��
		ListNode* fast = head;
		ListNode* slow = head; // ������ֻ�Ǽ�⻷������������ͷ�ڵ㿪ʼ����

		// ����⣬�������㣨ע������ƣ�����û����
		while (fast != nullptr && fast->next != nullptr) {

			//����
			slow = slow->next;
			fast = fast->next->next;

			// ��������
			if (slow == fast) {
				ListNode* index1 = fast;
				ListNode* index2 = head;

				// ���һ����
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;

				}
				return index2;


			}




		}
		return NULL;


	}


};

//#define DEBUG
#ifdef DEBUG

int main() {
	Solution solution;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);
	head->next->next->next->next->next->next->next = head->next->next->next;

	ListNode* result = solution.detectCycle(head);

	if (result != nullptr) {
		cout << "�ǻ����������뻷���ڣ�" << result << endl;

	}
	else {
		cout << "���ǻ�������" << endl;
	}

	

}



#endif