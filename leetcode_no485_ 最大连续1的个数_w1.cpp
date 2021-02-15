/* ------------------------------------------------------------------|
给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：

输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*	双指针法
*
*	执行用时：28 ms, 在所有 C++ 提交中击败了98.44%的用户
*	内存消耗：32.5 MB, 在所有 C++ 提交中击败了96.60%的用户
*/
int findMaxConsecutiveOnes(vector<int>& nums) {
    int l = 0;
    int r = 0;
    int res = 0;
    int count = 0;
    while (r < nums.size()) {
        if (nums[r++]) {
            count++;
        }
        else {
            res = max(res, count);
            while (r < nums.size() && !nums[r]) {
                r++;
            }
            l = r;
            count = 0;
        }
    }
    return max(res, count);
}

/*	单指针法
*
*	执行用时：36 ms, 在所有 C++ 提交中击败了91.31%的用户
*	内存消耗：32.5 MB, 在所有 C++ 提交中击败了96.60%的用户
*/
int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]) {
            count++;
        }
        else {
            res = max(res, count);
            count = 0;
        }
    }
    return max(res, count);
}