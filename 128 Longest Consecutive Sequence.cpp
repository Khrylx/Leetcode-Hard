#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) 
{
	int longest = 1;
	unordered_set<int> set(nums.begin(),nums.end());

	for (int i = 0; i < nums.size(); i++)
	{
		int lb = nums[i];
		
		if (set.count(lb-1))
			continue;

		int ub = nums[i]+1;
		while (set.count(ub))
		{
			ub++;
		}
		longest = max(longest,ub-lb);
	}

	return longest;
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	cout << longestConsecutive(nums) << endl;

	return 1;
}