#include"Header.h"
#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include"Header1.h"
using namespace std;
struct coordinates
{
	coordinates(int a,int b)
		:x(a),height(b){}

	int x;
	int height;
};


void swap(Object &a,Object &b)//swaping gor bubble sort
{
	int tempx=a.returnterx();
	int tempy=a.returnerheight();
	int tempz=a.returnerlabel();
	a.setcoordinatex(b.returnterx());
	a.setcoordinatey(b.returnerheight());
	a.setlabel(b.returnerlabel());
	b.setcoordinatex(tempx);
	b.setcoordinatey(tempy);
	b.setlabel(tempz);
}

void bubblesort(vector<Object> &x)//classic bubble sort
{
	for(int i=0;i<x.size()-1;i++)
	{
		for(int j=0;j<x.size()-i-1;j++)
		{
			if(x[j].returnterx()>x[j+1].returnterx())
			{
				swap(x[j],x[j+1]);
			}
		}
	}
}
void heapalgorithm(vector<Object>orderedx,MPQ<Object> &heap)//heap algorithm for inserting
{
	int control = 0;
	if(orderedx[0].returnterx()==0)//fisrtly these are for first index
	{
		heap.insert(orderedx[0],orderedx[0].returnerlabel());
		cout<<"0 "<<orderedx[0].returnerheight()<<endl;
	}
	
	else
	{
		cout<<"0 0"<<endl;
		heap.insert(orderedx[0],orderedx[0].returnerlabel());
	}

	for(int i=1;i<orderedx.size();i++)// it is a loop for working loop 
	{
		if(heap.searchinglabel(orderedx[i].returnerlabel()))//this means it is empty
		{
			if (control == 0)//control is for looking the first index
			{
				Object a0 = heap.getmax();
				cout << a0.returnterx() << " " << a0.returnerheight() << endl;
			}
			control = 1;
			Object a0=heap.getmax();
			int prevmax=a0.returnerheight();
			heap.insert(orderedx[i],orderedx[i].returnerlabel());// 
			Object a=heap.getmax();
			if(prevmax!=a.returnerheight()&&a0.returnterx() != orderedx[i-1].returnterx())//if it is not repetitive cout
				cout<<a.returnterx()<<" " <<a.returnerheight()<<endl;
			
		}
		else//this means it is not empty 
		{
			if (control == 0)
			{
				Object a0 = heap.getmax();
				cout << a0.returnterx() << " " << a0.returnerheight() << endl;
			}
			control = 1;
			Object a0=heap.getmax();
			int maxvalue=a0.returnerheight();
			heap.remove(orderedx[i].returnerlabel());//removing for the value
			Object a1=heap.getmax();
			if(a0!=a1 && a0.returnterx() != orderedx[i + 1].returnterx())// if it is not repetitive and 2. condition is not provided
			{
				cout<<orderedx[i].returnterx()<<" "<<heap.getmax().returnerheight()<<endl;
			}

		}
	}
	cout << orderedx[orderedx.size() - 1].returnterx() << " " << 0 << endl;
}



int main()
{
	ifstream f;
	string file="input.txt";
	f.open(file.c_str());
	string line,volumeofheaps;
	getline(f,volumeofheaps);
	int volumeofh=stoi(volumeofheaps);
	vector<Object> objectvector;
	MPQ<Object> heaps(2*volumeofh);
	int i=1;
	while(getline(f,line))
	{
		string number;
		stringstream ss(line);
		vector<int> coordinatesholder;
		while(ss>>number)
		{
			int a=stoi(number);
			coordinatesholder.push_back(a);
		}//creating a vector and sorting for x
		Object a(coordinatesholder[0],coordinatesholder[1],i);
		Object b(coordinatesholder[2],coordinatesholder[1],i++);// 
		coordinatesholder.clear();
	
		objectvector.push_back(a);
		objectvector.push_back(b);
	}
	bubblesort(objectvector);

	heapalgorithm(objectvector,heaps);
	cout << "yarrak" << endl;
	return 0;
}
