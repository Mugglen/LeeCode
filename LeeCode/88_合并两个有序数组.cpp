#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

	// 时间复杂度：O((m+n)log(m+n))。
	// 空间复杂度：O(log(m+n))。
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i != n; i++) {
			nums1[m + i] = nums2[i];
		}
		sort(nums1.begin(), nums1.end());
	}
};