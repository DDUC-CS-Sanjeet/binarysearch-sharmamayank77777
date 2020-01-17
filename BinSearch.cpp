#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	int mid;
	while(startIndex<=lastIndex)
	{
		mid=(startIndex+lastIndex)/2;
		if(array[mid]==element)
		return true;
		else
		if(array[mid]<element)
	    return	binarySearchReacursive(array,mid+1,lastIndex,element);
		else
		return	binarySearchReacursive(array,startIndex,mid-1,element);
	}
  return false;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int mid;
	while(startIndex<=lastIndex)
	{
		mid=(startIndex+lastIndex)/2;
		if(array[mid]==element)
		return true;
		else if(array[mid]<element)
		startIndex=mid+1;
		else
		lastIndex=mid-1;
		}	
  return false;
}

int main()
{
	int size;
	cout<<"Enter size of array:";
	cin>>size;
	int *array=new int[size],i,num;
	cout<<"\nEnter elements of array:";
	for(i=0;i<size;i++)
	cin>>array[i];
	cout<<"\nEnter element to be search:";
	cin>>num;
	sort(array,array+size);
	bool result1=binarySearchReacursive(array,0,size-1,num);
	bool result2=binarySearchIterative(array,0,size-1,num);
	cout<<"************* Recursive Result ***********";
	if(result1==0)
	cout<<"\nGiven number is not present in array";
	else
	cout<<"\nGiven number is present in array";
    cout<<"\n************* Iterative Result ***********";
    if(result2==0)
	cout<<"\nGiven number is not present in array";
	else
	cout<<"\nGiven number is present in array";
  
  return 0;
}
