#include "vec.h"
#include<vector>
#include<iostream>
#include<string>
using std::vector;
using std::cout;
using std::string;
int main() 
{
	vector<int> nums{10000,3,2};
	//vector<int> nums;
	//nums = {1000,3,2};

	cout<<"Size of nums: "<<nums.size()<<"\n";
	cout<<"Capacity of nums: "<<nums.capacity()<<"\n";
	cout<<"Max size of nums: "<<nums.max_size()<<"\n";
	nums.push_back(15);
	cout<<"Capacity of nums: "<<nums.capacity()<<"\n";
	cout<<nums[0]<<"\n\n\n";

	for(std::size_t i=0; i < nums.size(); ++i)
	{
		cout<<nums[i]<<"\n";
	}

	vector<int> nums2(10, 5);

	cout<<"for ranged\n";
	for(auto n: nums2)
	{
		cout<<n<<"\n";
	}
	vector<int> nums3;

	nums3.push_back(3);
	cout<<nums3[0]<<"\n";
	nums3[0] = 20;
	cout<<nums3[0]<<"\n";
	
	return 0;
}