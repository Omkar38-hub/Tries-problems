#include <bits/stdc++.h> 
using namespace std; 
#define ROW 4 
#define COL 3 


struct TrieNode
{
	TrieNode *child[2];
	TrieNode()
	{
		child[1]=child[0]=NULL;
	}
};
bool insert(TrieNode *root, int (*M)[COL],int row) 
{ 
	
	TrieNode *curr=root;
	bool flag=false;
	for(int i=0;i<COL;i++)
	{
		int index=M[row][i];
		if(curr->child[index]==NULL)
		{
		   flag=true;
		   curr->child[index]=new TrieNode();
		}
		curr=curr->child[index];
	}
	return flag;
} 

int main() 
{ 
	int M[ROW][COL] = {{1, 0, 0},  
                       {1, 1, 1},  
                       {1, 0, 0},  
                       {0, 1, 0}}; 
    TrieNode *root=new TrieNode();
    int res=0;
	cout<<"The number of distinct rows in the matrix is ";
	for(int i=0;i<ROW;i++)
	{
		if(insert(root,M,i)==true)
		   res++;
	}
	cout<<res<<"\n";
	return 0;		
} 
// time complexity =O(m*n)
//space is=O(m*n)
