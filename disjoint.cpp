#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	int rank;
	struct node* parent;
};


struct node* findSet(int a,unordered_map<int,struct node*>val_to_node)
{
	struct node* temp=val_to_node[a];
	if(temp==temp->parent)
	{
		return temp;
	}
	temp->parent=findSet(temp->parent->data,val_to_node);
	return temp->parent;

}

void Union(int a, int b, unordered_map<int,struct node*>val_to_node)
{
	struct node* parent1=findSet(a,val_to_node);
	struct node* parent2=findSet(b,val_to_node);
	if(parent1==parent2)
		return;
	else if(parent1->rank>parent2->rank)
	{
		parent2->parent=parent1;
	}
	else if(parent1->rank<parent2->rank)
	{
		parent1->parent=parent2;
	}
	else
	{
		parent2->parent=parent1;
		parent1->rank+=1;
	}			
}


struct node* makeSet(int a)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->rank=1;
	temp->parent=temp;
	return temp;
}
int main()
{
	unordered_map<int,struct node*> val_to_node;
	for(int i=1;i<=7;i++)
	{
		val_to_node[i]=makeSet(i);
	}

	Union(1,2, val_to_node);
	Union(2,3, val_to_node);
	Union(4,5, val_to_node);
	Union(6,7, val_to_node);
	Union(5,6, val_to_node);
	Union(3,7, val_to_node);
	struct node* temp=findSet(3, val_to_node);
	cout<<temp->data<<endl;

}