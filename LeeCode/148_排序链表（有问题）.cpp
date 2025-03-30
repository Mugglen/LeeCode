#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x = 0, ListNode* ptr = nullptr) : val(x), next(ptr) {}
};

class SolutionLF
{

public:
	// 测试用例过了，超长链表的时候报错了，不知道为啥（取出在vector中排序，再生成链表）
	ListNode* sortList_violence(ListNode* head) {
		
		// 异常值处理（空）
		if (head == nullptr) return head;

		// 创建vector存储链表值
		vector<int> vals;

		// 临时指针
		ListNode* curr = head;

		// 遍历链表
		while (curr != nullptr) {
			vals.push_back(curr->val);
			curr = curr->next;
			
		}

		// 释放内存
		curr = head;
		while (curr != nullptr) {
			ListNode* temp = curr;
			curr = curr->next;
			delete temp;  // 释放当前节点的内存
		}

		// 排序
		sort(vals.begin(), vals.end());

		// 创建新链表头
		ListNode* headSort = new ListNode();

		// 更新临时指针
		curr = headSort;

		for (int i : vals) {
			if (curr == nullptr) continue;
			curr->val = i;

			// ！！！！！注意这个边界处理，检测到是最后一个val后需要给nullptr
			curr->next = i != vals.back() ? new ListNode() : nullptr;
			curr = curr->next;
			

		}
		return headSort;
	}

	void vectorDebug(vector<int> vals) {
		for (int i : vals) {
			cout << i << ' ' << endl;
		
		}
	
	}
	
	// 需要学习一下归并


};

//作者：灵茶山艾府
//链接：https ://leetcode.cn/problems/sort-list/solutions/2993518/liang-chong-fang-fa-fen-zhi-die-dai-mo-k-caei/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 归并排序（分治）需要学习，还没搞懂
class Solution {
	// 876. 链表的中间结点（快慢指针）
	ListNode* middleNode(ListNode* head) {
		ListNode* pre = head;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			pre = slow; // 记录 slow 的前一个节点
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = nullptr; // 断开 slow 的前一个节点和 slow 的连接
		return slow;
	}

	// 21. 合并两个有序链表（双指针）
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode dummy; // 用哨兵节点简化代码逻辑
		ListNode* cur = &dummy; // cur 指向新链表的末尾
		while (list1 && list2) {
			if (list1->val < list2->val) {
				cur->next = list1; // 把 list1 加到新链表中
				list1 = list1->next;
			}
			else { // 注：相等的情况加哪个节点都是可以的
				cur->next = list2; // 把 list2 加到新链表中
				list2 = list2->next;
			}
			cur = cur->next;
		}
		cur->next = list1 ? list1 : list2; // 拼接剩余链表
		return dummy.next;
	}

public:
	ListNode* sortList(ListNode* head) {
		// 如果链表为空或者只有一个节点，无需排序
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		// 找到中间节点 head2，并断开 head2 与其前一个节点的连接
		// 比如 head=[4,2,1,3]，那么 middleNode 调用结束后 head=[4,2] head2=[1,3]
		ListNode* head2 = middleNode(head);
		// 分治
		head = sortList(head);
		head2 = sortList(head2);
		// 合并
		return mergeTwoLists(head, head2);
	}
};

//#define DEBUG
#ifdef DEBUG

int main() {


return 0;
}

#endif // DEBUG
