#ifndef _HEADER_H
#define _HEADER_H
#include<iostream>
using namespace std;
class Object
{
public:
	Object()
	{
		coordintaex=0;
		coordinateheight=0;
		label=0;
	}

	Object(int coordinate,int height,int labelim)
	{
		coordintaex=coordinate;
		coordinateheight=height;
		label=labelim;
	}
	Object(const Object &rhs)
	{
		coordintaex=rhs.coordintaex;
		coordinateheight=rhs.coordinateheight;
		label=rhs.label;
	}
	void operator=(const Object &rhs)
	{
		coordintaex=rhs.coordintaex;
		coordinateheight=rhs.coordinateheight;
		label=rhs.label;
	}

	bool operator ==(const Object&rhs)const
	{
		return coordinateheight==rhs.coordinateheight ? true:false;
	}
	bool operator !=(const Object&rhs)const
	{
		return coordinateheight!=rhs.coordinateheight ?true:false;
	}
	bool operator>(const Object&rhs)const
	{
		return coordinateheight>rhs.coordinateheight?true:false;
	}

	bool operator<(const Object&rhs)const
	{
		return coordinateheight<rhs.coordinateheight?true:false;
	}
	int returnterx()
	{return coordintaex;}
	int returnerheight()
	{	return coordinateheight;}
	int returnerlabel()
	{ return label;}
	void setcoordinatex(int x)
	{coordintaex=x;}
	void setcoordinatey(int y)
	{coordinateheight=y;}
	void setlabel(int x)
	{label=x;}




private:
	int coordintaex;
	int coordinateheight;
	int label;
};





#endif