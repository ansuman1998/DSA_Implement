#include<bits/stdc++.h>

using namespace std;
int main()
{
	int e1;
	cin>>e1;
	int e=e1;
	int u,v,w;
	vector<pair<int,pair<int,int> > > edges;
	while(e1!=0)
	{
		cin>>u>>v>>w;
		pair<int,int>temp;
		temp.first=u;
		temp.second=v;
		edges.push_back(pair<int,pair<int,int> >(w,temp));
		e1--;
	}

	sort(edges.begin(),edges.end());
	for(int i=0;i<e;i++)
		cout<<edges[i].first<<" "<<edges[i].second.first<<" "<<edges[i].second.second<<endl;
		
	int x,y,res=1;
	cin>>x>>y;
	while(y!=0)
	{
		if(y%2==1)
			res=res*x;
		x=x*x;
		y/=2;
	}
	cout<<res<<endl;
}