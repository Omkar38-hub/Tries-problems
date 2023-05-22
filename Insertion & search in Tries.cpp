#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
	TrieNode *child[26];
	bool isEnd;
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
		curr->isEnd=true;
	}
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
int main()
{
	string keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
	struct TrieNode *root=new TrieNode();
	for(int i=0;i<n;i++)
	   insert(root,keys[i]);
	search(root, "the")? cout << "Yes\n" :cout << "No\n";
    search(root, "these")? cout << "Yes\n" :cout << "No\n";
    return 0;
}
//Search // time complexity =O(n)
//Insert       time complextiy =theta(n)
