%{
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "m.h"
#include "datatypes.h"
using namespace std;
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern vector<string> netlistt;
extern vector<string> components;
extern vector<string> units;
extern vector<string> freq;
extern vector<string> amp;
void yyerror(const char* s);
%}
%union
{resistor* R;
inductorr* I;
capacitor* C;
int zero;
string* freq;
string* delay;
int vint;
int* sine;
float vfloat;
voltage* V;
resistance* r;
netlist* N;
inductance* ie;
capacitance* ce;
}
%token <sine> SINE
%token <freq> FREQUENCY
%token <delay> DELAY
%token <vint> INT
%token <vfloat> FLOAT
%token <r> RESISTANCE
%token <ie> INDUCTANCE
%token <ce> CAPACITANCE
%token <N> NETLIST
%token <R> RESISTOR
%token <I> INDUCTOR
%token <C> CAPACITOR
%token <V> VOLTAGE

%%
BISOR:
     IND BISOR
    |VOL BISOR
    |RES BISOR
    |CAP BISOR
    |RES
    |IND
    |CAP
    |VOL
    ;
RES:RESISTOR ham ham RESISTANCE
;
VOL:VOLTAGE ham ham SINE any any FREQUENCY DELAY any 
;
IND:INDUCTOR ham ham INDUCTANCE
;
CAP:CAPACITOR ham ham CAPACITANCE
;
ham:NETLIST
    |INT
;
any:INT
    |FLOAT
    |/*empty*/
;
%%
int main(int a,char** b)
{int radius=20;
int cenx=150;
int ceny=260;
//for(int y=0;y<nef.size();y++)
//{cout<<"X--> "<<nef[y].x<<endl<<"Y--> "<<nef[y].y<<endl;}
FILE *p= fopen("top.cir","r");
ofstream X;
X.open("OUT.svg");
string po=windowmaker(500,500);
X<<windowmaker(500,500)<<endl;
X<<ground(225,375)<<endl;
if (!p) {
		cout << "File not found" << endl;
		return 0;
	}
	yyin=p;
	do {
		yyparse();
	} while (!feof(yyin));
vector<compi>nef=CalC(components,netlistt);
//cout<<nef.size()<<endl;
for(int i=0;i<components.size();i++)
//cout<<nef[i].index;
{string check=components[nef[i].index];
//cout<<components[i]<<"\t"<<units[i]<<endl;
if (check.at(0)=='R')
        {if(nef[i].ang==0)
	X<<regester0(nef[i].dx,nef[i].dy)<<endl;
        else if(nef[i].ang==1)
	X<<regester1(nef[i].dx,nef[i].dy)<<endl;
	}
else if(check.at(0)=='L')
        {if(nef[i].ang==0)
	X<<inductor0(nef[i].dx,nef[i].dy)<<endl;
        else if(nef[i].ang==1)
	X<<inductor1(nef[i].dx,nef[i].dy)<<endl;
	}
else if((check.at(0)=='V')||(check.at(0)=='I'))
        {if(nef[i].ang==0)
	X<<volt0(nef[i].dx,nef[i].dy,radius)<<endl;
        else if(nef[i].ang==1)
	X<<volt1(nef[i].dx,nef[i].dy,radius)<<endl;
	}
else if(check.at(0)=='C')
        {if(nef[i].ang==0)
	X<<capacitorr0(nef[i].dx,nef[i].dy)<<endl;
        else if(nef[i].ang==1)
	X<<capacitorr1(nef[i].dx,nef[i].dy)<<endl;
	}
}
X<<"</svg>";
X.close();
return 0;
}
void yyerror(const char *s) {
	cout<<"Message: "<<s<<endl;
	exit(-1);
}
