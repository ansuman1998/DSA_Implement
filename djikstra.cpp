#include<bits/stdc++.h>
using namespace std;
struct myCompare{
	bool operator()(pair<int,int> const &a, pair<int,int> const &b)
	{
		return a.first>b.first || (a.first==b.first && a.second > b.second);
	}
};
int main()
{
	int n,e,u,v;
	vector<int>adj[n];
	cin>>n>>e;
	while(e!=0)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		e--;
	}
	unordered_map <int,pair<int,int>> node_to_pair;
	priority_queue <pair<int,int>,vector<pair<int,int>>, myCompare> minheap;
	for(int i=0;i<n;i++)
	{
		pair<int,int> temp;
		temp.first=INT_MAX;
		temp.second=i;
		node_to_pair[i]=temp;
		minheap.push(temp);
	}
	cout<<minheap.top().first<<endl;
	node_to_pair[3].first=1;
	node_to_pair[1].first=2;
	cout<<minheap.top().first;
}