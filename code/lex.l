%{
#include <cstdio>
#include <vector>
#include <iostream>
#include "datatypes.h"
#include "bis.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
vector<string> netlistt;
vector<string> components;
vector<string> units;
vector<string> freq;
vector<string> amp;
%} 
%%
[\t\n\) \(]+ ;
R[a-z0-9]+ {
components.push_back(strdup(yytext));
return RESISTOR;}
[I|V][a-z0-9]+ {
components.push_back(strdup(yytext));
return VOLTAGE;}
L[a-z0-9]+ {
components.push_back(strdup(yytext));
return INDUCTOR;}
C[a-z0-9]+ {
components.push_back(strdup(yytext));
return CAPACITOR;}
[0-9]+K {units.push_back(strdup(yytext));
return RESISTANCE;}
[0-9]+Khz {if(atof(yytext)!=0.0)
	freq.push_back(strdup(yytext));
	return FREQUENCY;}
[0-9]+\.[0-9]+ {amp.push_back(strdup(yytext));
	return FLOAT;}
[0-9]+ {if(atoi(yytext)==0)
        {if(netlistt.size()%2!=0)
            netlistt.push_back(strdup(yytext));
         }
	else if(atoi(yytext)!=0)
	amp.push_back(strdup(yytext));
return INT;}
[0-9]+\.[0-9]+S {return DELAY;}
[0-9]+[N|M]H {units.push_back(strdup(yytext));
return INDUCTANCE;}
[0-9]+[N|M]F {units.push_back(strdup(yytext));
return CAPACITANCE;}
[N|n][E|e][T|t][0-9]+ {
netlistt.push_back(strdup(yytext));
return NETLIST;}
SINE {return SINE;}
[a-zA-Z0-9]* { return 0;}
%%

