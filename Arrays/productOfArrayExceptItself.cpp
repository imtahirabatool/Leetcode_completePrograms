#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> start(n, 1);
        vector<int> end(n, 1);

        start[0] = nums[0];
        for(int i = 1; i < n; i++) {
            start[i] = start[i - 1] * nums[i];
        }
        end[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            end[i] = end[i + 1] * nums[i];
        }
        ans[0] = end[1];
        ans[n - 1] = start[n - 2];
        for(int i = 1; i < n - 1; i++) {
            ans[i] = start[i - 1] * end[i + 1];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> res = sol.productExceptSelf(nums);

    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Output: ";
    for(int num : res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
