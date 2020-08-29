#include<iostream>
using namespace std;
void Merge(int a[],int l,int m,int h){
	
	int i,j,k,s1=m-l+1,s2=h-m;
	int a1[s1];
	int a2[s2];
	
	for(i=0;i<s1;i++)
		a1[i]=a[l+i];    //copy left array
	for(j=0;j<s2;i++)
		a2[j]=a[m+1+j];  //copy right array
		
	// copying into a[l....h]
	i=0;
	j=0;
	k=l;
	while((i<s1)&&(j<s2))
	{
		if(a1[i]<=a2[j]){
			a[k]=a1[i];
			i++;
		}
		else{
			a[k]=a2[j];
			j++;
		}
		k++;
	}
	while(i<s1){
		a[k]=a1[i];
		i++;
		k++;
	}
	while(j<s2){
		a[k]=a2[j];
		j++;
		k++;
	}
	
}
void MergeSort(int a[],int l,int h){
	int mid;
	mid=l+(h-l)/2;
//	cout<<mid;
	MergeSort(a,l,mid);
	MergeSort(a,mid+1,h);
	Merge(a,l,mid,h);
}

main()
{
	int a[7]={1,3,4,12,5,2,11};
	cout<<"Original Array :\n";
	for(int i=0;i<7;i++)cout<<a[i]<<" ";
	cout<<endl;
	MergeSort(a,0,6);
	cout<<"Sorted Array :\n";
	for(int i=0;i<7;i++)cout<<a[i]<<" ";
	cout<<endl;
}
