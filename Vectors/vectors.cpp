//vectors 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> vec1 = {1,2,3,4};
	
	cout<<"vector size is "<<vec1.size()<<endl;
	cout<<"vector capacity is "<<vec1.capacity()<<endl;
	
	vec1.push_back(5);
	
	cout<<"vector size is "<<vec1.size()<<endl;
	cout<<"vector capacity is "<<vec1.capacity()<<endl;
	
	for(int i=0; i<vec1.size(); i++)
	{
		cout<<vec1[i]<<" ";
	}
}
