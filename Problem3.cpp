#include <vector>
#include <bits/stdc++.h>
using namespace std;
int binsearch(vector <int> v,int a,int b,int x)
{
	if(b-a<=1)
	{
		if(x<=v[a])
			return a;
		else
			return b;
	}
	int m=int((a+b)/2);
	if(x<=v[m])
		return binsearch(v,a,m,x);
	return binsearch(v,m,b,x);
}
 
int test(vector <int> v,int k,int sz)
{
	vector <int> w;
	int currentmax=0;
	w.push_back(v[k]);
	for(int i=0;i<sz;i++)
	{
		int abc=v[(i+k)%sz];
		int xx=(upper_bound(w.begin(),w.end(),abc)-w.begin());
		if(abc>w[w.size()-1]){
			
			w.push_back(abc);}
			else if(xx>0 && w[xx-1]==abc)
			{
			}
			else
			{
				w[xx]=abc;
			}
	}
	
	return w.size();
}
 
 
int main()
{
	int t;
	cin >> t;
	
	for(int i=0;i<t;i++)
	{
		int a;
		cin >> a;
		vector <int> v(a);
		for(int j=0;j<a;j++)
		{
			int b;
			cin >> v[j];
		}
		
		int currentmax=0;
		for(int k=0;k<a;k++)
		{
			int xxx=test(v,k,a);
			if(currentmax<xxx)
				currentmax=xxx;
		}
		cout << currentmax << endl;
	}
}
