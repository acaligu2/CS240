#include "string_graph.h"

coursegraph::coursegraph(int v,vector<string> coursename)
{
	this->v = v;
	this->array = new courselist[v];
	for(int i=0;i<v;i++)
	{
		array[i].srcname = coursename[i];
		array[i].head = NULL;
	}
}

coursenode* coursegraph::newnode(string coursename)
{
	coursenode* newnode = new coursenode;
	newnode->coursename = coursename;
	newnode->next = NULL;
	return newnode;
}

int coursegraph::getindex(string name)
{
	for(int i=0;i<v;i++)
	{
		if(array[i].srcname == name)
			return i;
	}
	return -1;
}

void coursegraph::addEdge(string src,string dest)
{
	coursenode *node = newnode(dest);
	int index = getindex(src);
	node->next = array[index].head;
	array[index].head = node;
}

bool coursegraph::isrequire(string srcname,string desname)
{
	int src = getindex(srcname);
	int des = getindex(desname);
	coursenode *temp = array[src].head;
	while(temp)
	{
		if(desname == temp->coursename)
			return true;
		temp = temp->next;
	}
	return false;
}

void coursegraph::print()
{
	int i;
	for(i=0;i<v;i++)
	{
		coursenode *temp = array[i].head;
		cout<<"Vertex "<<i<<" "<<array[i].srcname<<endl;
		while(temp)
		{
			cout<<"-> "<<temp->coursename<<endl;
			temp = temp->next;
		}
		cout<<endl;
	}
}

string coursegraph::getrequire(string coursename)
{
	int courseindex = getindex(coursename);
	if(courseindex == -1){ return " "; }
	coursenode *temp = array[courseindex].head;
	if(temp == NULL)
		return " ";
	return temp->coursename;
}

coursegraph::~coursegraph()
{
	int i;
	coursenode *temp,*tempnode;
	for(i=0;i<v;i++)
	{
		temp = array[i].head;
		while(temp)
		{
			tempnode = temp;
			temp = temp->next;
			delete tempnode;
		}
	}
	delete [] array;
}

