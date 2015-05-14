#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node{
	int end;
	node *child[26];
}*root;

node *cnn()
{
	node *ptr=new node;
	ptr->end=0;
	for(int i=0;i<26;i++)
	ptr->child[i]=NULL;
	
	return ptr;
}

void insert(string str,int l)
{
	int i,j,k;
	node *nptr,*p;
	//l=strlen(str);
	if(root==NULL)
	{
		k=str[0]-'a';
		root=cnn();
		//nptr=cnn();
		nptr=root->child[k]=cnn();//str[0];
		i=1;
		while(i<l)
		{
			k=str[i]-'a';
			//p=cnn();
			p=nptr->child[k]=cnn();//str[i];
			nptr=p;
			i++;
		}
		nptr->end=1;
	}
	else
	{
		i=0;
		nptr=root;
		while(i<l)
		{
			k=str[i]-'a';
			//p=cnn();
			if(nptr->child[k]==NULL)
			nptr=nptr->child[k]=cnn();//str[i];
			else
			nptr=nptr->child[k];
			i++;
		}
		nptr->end=1;
	}
}

int search(string s,int l)
{
	node *q;
	if(root==NULL)
	return 0;
	else
	{
		int i=1;
		q=root->child[s[0]-'a'];
		if(q==NULL)
		return 0;
		while(i<l)
		{
			q=q->child[s[i]-'a'];
			if(q==NULL)
			return 0;
			i++;
		}
		if(q->end==1)
		return 1;
	}
	return 0;
}

int main()
{
	root=NULL;
	char ch='y';
	string str;
	int l,s;
	
	while(ch=='y')
	{
		cin>>str;
		l=str.size(); //cout<<l;
		insert(str,l);
		cout<<"\nEnnter [ y ] to insert more word :- ";
		cin>>ch;
	}
	
	cout<<"\nEnter word to search :- ";
	ch='y';
	while(ch=='y')
	{
		cin>>str;
		l=str.size();
		s=search(str,l);
		if(s==1)
		cout<<"Entered word is present in Dictionary ";
		else
		cout<<"\nEntered word is not present in Dictionary\nEnter [ y ] to search more words :-";
		cin>>ch;
	}
}
