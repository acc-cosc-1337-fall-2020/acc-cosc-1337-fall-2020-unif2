#include "vec.h"
#include<vector>
#include<iostream>
using std::vector;
using std::cout;
int main() 
{
	vector<int> nums{10,3,2};

	cout<<"Size of nums: "<<nums.size()<<"\n";
	cout<<"Capacity of nums: "<<nums.capacity()<<"\n";
	cout<<"Max size of nums: "<<nums.max_size()<<"\n";
	nums.push_back(15);
	cout<<"Capacity of nums: "<<nums.capacity()<<"\n";
	cout<<nums[3]<<"\n";

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