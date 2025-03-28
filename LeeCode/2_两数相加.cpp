#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};



class Solution {

public:

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		
		// �Ȱѱ�ͷ������ݽڵ�,��ͷָ���������ڵ���
		ListNode* head = new ListNode(0);
		ListNode* curr = head;
		int carry = 0;

		// ͬʱ�����������Ⱥͽ�λ
		while (l1 || l2 || carry) {

			// ȡֵ
			int a = l1 ? l1->val : 0;
			int b = l2 ? l2->val : 0;
			int sum = a + b + carry;

			// ��λ�ж�
			carry = sum >= 10 ? 1 : 0;

			// �½��ڵ�洢������
			curr->next = new ListNode(sum % 10);

			// �ƶ����½ڵ�
			curr = curr->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		// ���ر�ͷָ�뱸��
		return head->next;
	}

	void buildList(ListNode*& listHead1, ListNode*& listHead2 ) {

		// ��һ�����봦��
		string line1;
		getline(cin, line1);
		stringstream ss1(line1);
		string token1;
		ListNode* curr1 = listHead1;
		while (getline(ss1, token1, ',')) {
			listHead1->next = new ListNode(stoi(token1));
			curr1 = curr1->next;
		}

		// �ڶ������봦��
		string line2;
		getline(cin, line2);
		stringstream ss2(line2);
		string token2;
		ListNode* curr2 = listHead2;
		while (getline(ss2, token2, ',')) {
			listHead2->next = new ListNode(stoi(token2));
			curr2 = curr2->next;
		}
	}
};


#define DEBUG
#ifdef DEBUG

int main() {

	// io����
	ListNode* head1 = new ListNode(-1);
	ListNode* head2 = new ListNode(-1);
	
	Solution solution;
	solution.buildList(head1, head2);

	ListNode* resultHead =  solution.addTwoNumbers(head1, head2);

	cout << "�����ͽ��Ϊ��" << endl;
	while (resultHead -> next != nullptr) {
		cout << resultHead->val << ' ' << endl;
	
	}

}



#endif
