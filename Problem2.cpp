#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define pb push_back
 
struct AvoidRoads{
long long numWays(int width, int height, vector <string> bad)
{
     long long dp[101][101];
	long cnt=1,block[101][101],i,j,v,p,q;
	vector<long> t;
	string s,r;
 
    memset(block,0,sizeof(block));
	for(i=0;i<bad.size();i++)
	{
		s=bad[i];
		r="";
		for(j=0;j<s.length();j++)
		{
			if(s[j]!=' ')
			{
				r+=s[j];
			}
			else
			{
				t.pb(atoi(r.c_str()));
				r="";
			}
		}
		t.pb(atoi(r.c_str()));
		if(!block[t[0]][t[1]] && !block[t[2]][t[3]])
            block[t[0]][t[1]]=block[t[2]][t[3]]=cnt++;
        else if(block[t[0]][t[1]])
        {
            if(!block[t[2]][t[3]])
                block[t[2]][t[3]]=block[t[0]][t[1]];
            else
            {
                v=block[t[2]][t[3]];
                for(p=0;p<=width;p++)
                for(q=0;q<=height;q++)
                if(block[p][q]==v)
                block[p][q]=block[t[0]][t[1]];
            }
        }
        else if(block[t[2]][t[3]])
            block[t[0]][t[1]]=block[t[2]][t[3]];
		t.clear();
	}
 
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=0;i<=width;i++)
	{
		for(j=0;j<=height;j++)
		{
			if(i>0 && ((block[i][j]==0 && block[i-1][j]==0) || block[i][j]!=block[i-1][j]))
				dp[i][j]+=dp[i-1][j];
			if(j>0 && ((block[i][j]==0 && block[i][j-1]==0) || block[i][j]!=block[i][j-1]))
				dp[i][j]+=dp[i][j-1];
		}
	}
    return dp[width][height];
}
 
 
};
 
