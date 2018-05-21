#include<string>
#ifndef __DATATYPES_H_
#define __DATATYPES_H_
using namespace std;
class resistor
{
public:
    string name,net1,net2;
    string value;
};
class inductorr
{public:
    string name,net1,net2;
    string value;

};
class capacitor
{public:
    string name,net1,net2;
    string value;
};
class voltage
{public:
    string name,net1,net2;
    string value;
};
class netlist
{public:
    string name;

};
class paired
{public:
	string p1,p2;
	int connect=0;
	int srs=0;
	int baseo;
	float basex,basey;
};
class compi
{public:
	int index;
	float dx,dy,t1x,t1y,t2x,t2y;
	int ang=0;
	void reg(int a)
	{
	if(a==0)
	{t2x=dx;t2y=dy;t1x=dx-8;t2y=dy-44;
	}
	else if(a==1)
	{t2x=dx;t2y=dy;t1x=dx+44;t1y=dy-8;
	}
	}
	void ind(int a)
	{
	if(a==0)
	{t2x=dx;t2y=dy;t1x=dx;t1y=dy-90;}
	else if(a==1)
	{t2x=dx;t2y=dy;t1x=dx+90;t1y=dy;}
	}
	void caps(int a)
	{
	if(a==0)
	{t2x=dx+15;t2y=dy-10;t1x=dx+15;t1y=dy+15;}
	else if(a==1)
	{t2x=dx-10;t2y=dy+15;t1x=dx+15;t1y=dy+15;}
	}
	void volt(int a)
	{
	if(a==0)
	{t2x=dx;t1x=dx;t1y=dy-40;t2y=dy+40;}
	else if(a==1)
	{t2x=dx+40;t2y=dy;t1x=dx-40;t1x=dx;}
	}
};
class capacitance
{public:
    string name;
};
class inductance
{public:
    string name;
};
class resistance
{public:
    string name;
}; 
extern "C" {
int yyparse(void);
int yylex(void);
int yywrap(void);
}
#endif
 
