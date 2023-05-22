#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
	bool isEnd;
	TrieNode *child[26];
	TrieNode()
	{
		isEnd=false;
		for(int i=0;i<26;i++)
		  child[i]=NULL;
	}
};
void insert(TrieNode *root,string str)
{
	TrieNode *curr=root;
	for(int i=0;i<str.length();i++)
	{
		int index=str[i]-'a';
		if(curr->child[index]==NULL)
		    curr->child[index]=new TrieNode();
		curr=curr->child[index];
	}
	curr->isEnd=true;
}
bool search(TrieNode *root,string str)
{
	TrieNode *curr=root;
	for(int i=0;i<str.length();i++)
	{
		int index=str[i]-'a';
		if(curr->child[index]==NULL)
		    return false;
		curr=curr->child[index];
	}
	return curr->isEnd;
}
bool isEmpty(TrieNode *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		  return false;
	}
	return true;
}
TrieNode *deleting(TrieNode *root,string str,int i)
{
	if(root==NULL)
	   return NULL;
	if(i==str.length())
	{
		root->isEnd=false;
		if(isEmpty(root))
		{
			delete(root);
			root=NULL;
		}
		return root;
	}
	int index=str[i]-'a';
	root->child[index]=deleting(root->child[index],str,i+1);
	if(isEmpty(root) && root->isEnd==false)
	{
		delete(root);
		root=NULL;
	}
	return root;
}
int main()
{
	TrieNode *root=new TrieNode();
	string str[]={"an","and","ant","bad","bat","zoo"};
	int n=sizeof(str)/sizeof(str[0]);
	for(int i=0;i<n;i++)
	   insert(root,str[i]);
	cout<<"Deleting 'and' from the dictionary....\n";
	root=deleting(root,"and",0);
	cout<<"'and' deleted successfully\n\n";
	cout<<" Is now 'and'  present in the dictionary?\n ";
	if(search(root,"and"))
	   cout<<"YES";
	else
	    cout<<"NO";
	return 0;
}
// time complexity =O(n)
