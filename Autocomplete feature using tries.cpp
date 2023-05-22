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
bool Last(TrieNode *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->child[i])
		  return false;
	}
	return true;
}
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
void suggestionsRec(TrieNode *root,string str)
{
	if(root->isEnd)
	{
		cout<<str<<"\n";
	}
	if(Last(root))
	  return;
	for(int i=0;i<26;i++){
		if(root->child[i])
		{
			str+=(i+97);
			suggestionsRec(root->child[i],str);
			str.pop_back();
		}
	}
}
int printAutoSuggestions(TrieNode *root,string str)
{
	TrieNode *curr=root;
	for(int i=0;i<str.length();i++)
	{
		int index=str[i]-'a';
		if(curr->child[index]==NULL)
		   return 0;
		curr=curr->child[index];
	}
	bool wordEnd=(curr->isEnd==true);
	bool isLast=Last(curr);
	if(wordEnd && isLast)
	{
		cout<<str<<"\n";
		return -1;
	}
	if(!isLast)
	{ 
        suggestionsRec(curr,str); 
        return 1; 
	}
}
int main()
{
	TrieNode *root=new TrieNode();
	insert(root, "hello"); 
    insert(root, "dog"); 
    insert(root, "hell"); 
    insert(root, "cat"); 
    insert(root, "a"); 
    insert(root, "hel"); 
    insert(root, "help"); 
    insert(root, "helps"); 
    insert(root, "helping"); 
    int comp = printAutoSuggestions(root, "hel"); 
    if (comp == -1) 
        cout << "No other strings found with this prefix\n"; 
    else if (comp == 0) 
        cout << "No string found with this prefix\n"; 
    return 0; 
}

