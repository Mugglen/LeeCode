#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/35-%E5%89%91%E6%8C%87offer.html
    int InversePairs(vector<int>& nums) {
        // ʱ�临�Ӷ�Ҫ��O(n),���ܱ�����,����д������
        const int kmod = 1000000007;
        int ret = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    ret += 1;
                    ret %= kmod; // �п������ʱ��,��ÿ�ζ�modһ��
                }
            }
        }
        return ret;
    }
};

#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2
class Solution {
public:
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/35-%E5%89%91%E6%8C%87offer.html
    // �����ù鲢��������WXG������˺��
    int InversePairs(vector<int>& nums) {
        // ����
        if (nums.size() == 0) return 0;
		vector<int> copy(nums);// �������飬ÿ�εݹ������
        return recursion(nums, copy, 0, nums.size() - 1);
    }
};

#endif // DEBUG2