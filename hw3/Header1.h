#ifndef _MPQ_H
#define _MPQ_H
#include<iostream>
#include<string>
#include<vector>

using namespace std;


template<class Comparable>
class MPQ
{
public:
	MPQ(int size)
		:array( size), location(size)
	{};

		~MPQ() {};
		bool searchinglabel(int labelnum)
		{
			return location[labelnum]==0?true:false;
		}
		int nextelement(int a)
		{
			return array[a + 1].returnterx();
		}

		void insert(Comparable value, int label)//inserting the object to array
		{
			int hole=++currentSize;
			while(hole>1 && value>array[hole/2])
			{
				array[hole]=array[hole/2];
				location[array[hole].returnerlabel()]=hole;
				hole=hole/2;
			}
			array[hole]=value;
			location[label]=hole;

		}
		int returningcountsize()
		{
			return currentSize;
		}
		Comparable remove( int label)
		{
			if (currentSize==0) {
				throw "There is no such item";

			}
			else
			{// it is a normal removoving for heap bu the difference it is not first node 
				
				Comparable tmp35;// böyle constructor yok !!
				Comparable removed = array[location[label]];
			
				array[location[label]] = array[currentSize--];
				array[currentSize + 1] = tmp35;
			
				location[label] = 0;

				percolateDown(label);
				return removed;
			}
		}

		Comparable getmax()// it is O(n) getting max 
		{
			Comparable max=array[1];
			for(int i=1;i<array.size();i++)
			{
				if(array[i]>max)
				{
					max=array[i];
				}
			}
			return max;
		}
		int getlabel(int label)
		{
			return location[label];
		}


	private:
		void percolateDown(int hole)
		{
			int child;
			Comparable tmp = array[ hole ]; // tmp is the item that will
			// be percolated down

			for( ; hole * 2 <= currentSize; hole = child )
			{
				child = hole * 2;
				if( child != currentSize && array[ child + 1 ] < array[ child ] )
					child++;  // child is the minimum of the children
				if( array[ child ] < tmp )
				{
					array[ hole ] = array[ child ]; // swap hole and min child
					location[array[hole].returnerlabel()] = hole;
				}
				else
					break;
			}
			array[ hole ] = tmp;
			location[array[hole].returnerlabel()] = hole;
		}
		vector<Comparable>array;
		vector<int>location;
		int currentSize;

	};






#endif
