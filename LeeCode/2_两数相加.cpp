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
		
		// 先把表头存个备份节点,表头指针存在这个节点里
		ListNode* head = new ListNode(0);
		ListNode* curr = head;
		int carry = 0;

		// 同时考虑两个表长度和进位
		while (l1 || l2 || carry) {

			// 取值
			int a = l1 ? l1->val : 0;
			int b = l2 ? l2->val : 0;
			int sum = a + b + carry;

			// 进位判断
			carry = sum >= 10 ? 1 : 0;

			// 新建节点存储运算结果
			curr->next = new ListNode(sum % 10);

			// 移动到新节点
			curr = curr->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		// 返回表头指针备份
		return head->next;
	}

	void buildList(ListNode*& listHead1, ListNode*& listHead2 ) {

		// 第一行输入处理
		string line1;
		getline(cin, line1);
		stringstream ss1(line1);
		string token1;
		ListNode* curr1 = listHead1;
		while (getline(ss1, token1, ',')) {
			listHead1->next = new ListNode(stoi(token1));
			curr1 = curr1->next;
		}

		// 第二行输入处理
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

	// io处理
	ListNode* head1 = new ListNode(-1);
	ListNode* head2 = new ListNode(-1);
	
	Solution solution;
	solution.buildList(head1, head2);

	ListNode* resultHead =  solution.addTwoNumbers(head1, head2);

	cout << "两数和结果为：" << endl;
	while (resultHead -> next != nullptr) {
		cout << resultHead->val << ' ' << endl;
	
	}

}



#endif
