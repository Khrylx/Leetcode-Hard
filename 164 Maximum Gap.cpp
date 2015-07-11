#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
struct Bucket
{
	vector<int> Elements;
};

int maximumGap(vector<int>& nums) 
{
	int BNum = nums.size();
	if (nums.size() < 2)
	{
		return 0;
	}
	int maxVal = *max_element(nums.begin(),nums.end());
	int minVal = *min_element(nums.begin(),nums.end());
	int BSize = (maxVal - minVal) / BNum + 1;

	Bucket* buckets = new Bucket[BNum];

	for (int i = 0; i < nums.size(); i++)
	{
		int BIndex = (nums[i]-minVal) / BSize;
		vector<int>& eVec = buckets[BIndex].Elements;
		eVec.push_back(nums[i]);
		int k = (int)eVec.size()-2;
		while (k >= 0 && eVec[k] > eVec[k+1])
		{
			swap(eVec[k],eVec[k+1]);
			k--;
		}
	}

	int maxGap = -1;
	int count = 0;
	int pre = -1;

	for (int i = 0; i < BNum && count < nums.size(); i++)
	{
		vector<int>& eVec = buckets[i].Elements;
		if (eVec.empty())
			continue;

		for (int j = 0; j < eVec.size(); j++)
		{
			if (pre >= 0)
			{
				maxGap = max(eVec[j]-pre,maxGap);
			}
			pre = eVec[j];
			count++;
		}
	}

	delete[] buckets;
	return maxGap;
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
	int sol = maximumGap(nums);
	return 1;
}