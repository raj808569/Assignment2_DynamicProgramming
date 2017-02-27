#include<stdio.h>
#include<iostream.h>
using namespace std;
int main()
{
int n;
cout<<"enter the length of array";
cin>>n;
 int arr[n];
cout<<"enter the array elements";
 for(int i=0;i<n;i++)
  cin>>arr[i];
  int lis[n][2]={{0}};
  lis[0][0]=lis[0][1]=1;
  int maxseq=1;
  for(int k=1;k<n;k++)
  {
    for(int p=k-1;p>=0;p--)
    {
        if(arr[p] <arr[k]) lis[k][0] = max(lis[p][1]+1,lis[k][0]);
      if(arr[j] >arr[i]) lis[i][1] = max(lis[p][0]+1,lis[k][1]);

    }
    maxseq=max(maxseq,max(lis[k][0],lis[k][1]));
  }
  cout<<"maximum length of zigzag subsequence is :"<<maxseq<<endl;
return 0;
}
