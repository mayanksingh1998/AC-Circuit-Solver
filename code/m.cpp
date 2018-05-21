#include <iostream>
#include <string>
#include <fstream>
#include "m.h"
#include <cmath>
#include <vector>
using namespace std;
string windowmaker(int a,int b){
	string s= "<svg width=\""+to_string(a)+"\" "+" height=\""+to_string(b)+"\">";
	return s;
}
 string line(int a,int b ,int c,int d){
 	string  s= "<line x1=\""+to_string(a)+"\" "+"  y1=\""+to_string(b)+"\" x2=\""+to_string(c)+"\""+"  y2=\""+to_string(d)+"\" stroke=\"black\" stroke-width=\"3\"/>";
 	return s; 
	}
string regester0(int a ,int b){
	string s= 	"<path d=\"m"+to_string(a)+","+to_string(b)+" 8,11 h-8 l8,11 h-8 l8,11 h-8 l8,11\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" stroke-linecap=\"square\"/>";
	return s;
}
string regester1(int a ,int b)
{string s ="<path d=\"m"+to_string(a)+","+to_string(b)+" 11,8 v-8 l11,8 v-8 l11,8 v-8 l11,8\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" stroke-linecap=\"square\"/>";
	return s;

}
string inductor1(int a, int b){
	string s= "<path d=\"m"+to_string(a)+","+to_string(b)+" h10 c0,-11 8,-11 8,0 0,-11 8,-11 8,0 0,-11 8,-11 8,0 h10\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" stroke-linecap=\"square\"/>";
	return s;
}
string inductor0(int a, int b){
	string s= "<path d=\"m"+to_string(a)+","+to_string(b)+" v10 c-11,0 -11,8 0,8 -11,0 -11,8 0,8 -11,0 -11,8 0,8 v10\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" stroke-linecap=\"square\"/>";
	return s;
}

string ground(int a,int b){
	string s = line(a,b,a+50,b)+ "\n" + line(a+10,b+5,a+40,b+5)+"\n" + line(a+20,b+10,a+30,b+10)+"\n" + line(a+25,b-15,a+25,b)+"\n" + line(a+25,b-15,a-75,b-15)+"\n" + line(a+25,b-15,a+125,b-15)+"\n" + line(a-75,b-15,a-75,b-75)+"\n";// + line(a+125,b-15,a+125,b-75);
	return s;
}
string volt0(int a,int q,int r){
	string s= "<circle cx=\""+to_string(a)+"\" "+" cy=\""+to_string(q)+"\" r=\""+to_string(r)+"\" stroke=\"black\" stroke-width=\"3\"  fill=\"none\" /> \n <path fill=\"none\" stroke=\"black\" stroke-width=\"3\" d=\"m"+to_string(a-15)+","+to_string(q)+" q5,-17 15,0\" />  \n <path fill=\"none\" stroke=\"black\" stroke-width=\"3\" d=\"m"+to_string(a)+","+to_string(q)+" q10,15 15,0\" />"+ "\n" + line(a,q-20,a,q-40)+ "\n" + line(a,q+20,a,q+40);
	return s;
}
string volt1(int a,int q,int r){
	string s= "<circle cx=\""+to_string(a)+"\" "+" cy=\""+to_string(q)+"\" r=\""+to_string(r)+"\" stroke=\"black\" stroke-width=\"3\"  fill=\"none\" /> \n <path fill=\"none\" stroke=\"black\" stroke-width=\"3\" d=\"m"+to_string(a-15)+","+to_string(q)+" q5,-17 15,0\" />  \n <path fill=\"none\" stroke=\"black\" stroke-width=\"3\" d=\"m"+to_string(a)+","+to_string(q)+" q10,15 15,0\" />"+ "\n" + line(a-20,q,a-40,q)+ "\n" + line(a+20,q,a+40,q);
	return s;
}

string capacitorr1(int a,int b){
	string s = line(a,b,a+10,b)+ "\n" + line(a+15,b,a+25,b)+ "\n" + line(a+10,b+10,a+10,b-10)+ "\n" + line(a+15,b+10,a+15,b-10);
	return s;
}
string capacitorr0(int a,int b)
	{string s = line(a,b,a,b+10)+ "\n" + line(a,b+15,a,b+25)+"\n" + line(a+10,b+10,a-10,b+10)+ "\n" + line(a+10,b+15,a-10,b+15);
	return s;
	}
bool doone(vector<int> a,int b)
{int k=123123123;
for(int i=0;i<a.size();i++)
{if(a[i]==b)
	k=b;
}
if(k!=123123123)
return true;
else
	return false;
}
vector<compi> CalC(vector<string> comp,vector<string> net)
{
compi pushh;
paired pt;
vector<paired> con;
vector<int> done;
vector<compi> jam;
int f=0;int count=0;
for(int i=0;i<comp.size();i++)
{string check=comp[i];
if(check.at(0)=='V')
        {if(net[f+1]==to_string(0))
		{done.push_back(f/2);
		pt.p1=net[f];
		pt.p2=net[f+1];
		pt.connect++;
		pt.basex=150;
		pt.basey=220;
		pt.baseo=0;
		pushh.index=f/2;
		pushh.dx=150+pow(-1,count)*count*45;
		pushh.dy=260;
		pushh.t1x=150+pow(-1,count)*count*45;
		pushh.t1y=220;
		pushh.t2x=150+pow(-1,count)*count*45;
		pushh.t2y=300;
		pushh.ang=0;
		count++;
		jam.push_back(pushh);
		}
		
	}
else if(check.at(0)=='I')
{//cout<<i<<f+1<<"\t"<<net[f+1];
	if(net[f+1]==to_string(0))
		{done.push_back(f/2);
		pt.p1=net[f];
		pt.p2=net[f+1];
		pt.connect++;
		pt.basex=150;
		pt.basey=220;
		pt.baseo=0;
		pushh.index=f/2;
		pushh.dx=150+pow(-1,count)*count*45;
		pushh.dy=260;
		pushh.t1x=150+pow(-1,count)*count*45;
		pushh.t1y=220;
		pushh.t2x=150+pow(-1,count)*count*45;
		pushh.t2y=300;
		pushh.ang=0;
		count++;
		jam.push_back(pushh);
		}
		
	}
f=f+2;
}
con.push_back(pt);
while(jam.size()<comp.size())
{for(int I=0;I<net.size();I+=2)
	{for(int j=0;j<con.size();j++)
	{ if((net[I]+net[I+1]==con[j].p1+con[j].p2)||(net[I]+net[I+1]==con[j].p2+con[j].p1))
	 {if(!doone(done,I/2))
		{done.push_back(I/2);
		pushh.index=I/2;
		pushh.ang=con[j].baseo;
		if(pushh.ang==0)
		{pushh.dx=con[j].basex+30+con[j].connect*25;
		pushh.dy=con[j].basey;}
		else if(pushh.ang==1)
		{pushh.dx=con[j].basex;
		pushh.dy=con[j].basey-30-con[j].connect*5;}
		con[j].connect++;
		string h=comp[I/2];
		if(h.at(0)=='R')
			pushh.reg(pushh.ang);
		else if(h.at(0)=='L')
			pushh.ind(pushh.ang);
		else if((h.at(0)=='V')||(h.at(0)=='I'))
			pushh.volt(pushh.ang);
		else if(h.at(0)=='C')
			pushh.caps(pushh.ang);
		jam.push_back(pushh);
		cout<<"THIS"<<endl;
	 }
	 }
	}for(int j=0;j<con.size();j++)
	{
	if(net[I+1]=="0")
	{if(net[I]==con[j].p1||net[I+1]==con[j].p1||net[I]==con[j].p2)
	{if(!doone(done,I/2))
		{done.push_back(I/2);
		con[j].srs++;
		pt.p1=net[I];
		pt.p2=net[I+1];
		pt.connect++;
		if(con[j].baseo==0)
		{pt.basex=con[j].basex+20+con[j].srs*15;
		pt.basey=con[j].basey-15;
		pt.baseo=1;
	//cout<<con[j].srs<<"\t"<<pt.basex<<endl;
		}
		else if(con[j].baseo==1)
		{pt.basex=con[j].basex+25;
		pt.basey=con[j].basey+con[j].srs*20;
		pt.baseo=0;
		//cout<<"FH"<<endl;
		}
		con.push_back(pt);
		pushh.index=I/2;
		pushh.dx=pt.basex;
		pushh.dy=pt.basey;
		pushh.ang=pt.baseo;
		string h=comp[I/2];
		if(h.at(0)=='R')
			pushh.reg(pushh.ang);
		else if(h.at(0)=='L')
			pushh.ind(pushh.ang);
		else if((h.at(0)=='V')||(h.at(0)=='I'))
			pushh.volt(pushh.ang);
		else if(h.at(0)=='C')
			pushh.caps(pushh.ang);
		jam.push_back(pushh);
		cout<<"L@"<<endl;
		}
  		}
	 }
	else if(net[I+1]!="0")
	{if(net[I]==con[j].p1||net[I+1]==con[j].p1||net[I]==con[j].p2||net[I+1]==con[j].p2)
	{if(!doone(done,I/2))
		{done.push_back(I/2);
		con[j].srs++;
		pt.p1=net[I];
		pt.p2=net[I+1];
		pt.connect++;
		if(con[j].baseo==0)
		{pt.basex=con[j].basex+20+con[j].srs*15;
		pt.basey=con[j].basey-15;
		pt.baseo=1;
	//cout<<con[j].srs<<"\t"<<pt.basex<<endl;
	}
		else if(con[j].baseo==1)
		{pt.basex=con[j].basex+25;
		pt.basey=con[j].basey+con[j].srs*20;
		pt.baseo=0;
		//cout<<"FH"<<endl;
		}
		con.push_back(pt);
		pushh.index=I/2;
		pushh.dx=pt.basex;
		pushh.dy=pt.basey;
		pushh.ang=pt.baseo;
		string h=comp[I/2];
		if(h.at(0)=='R')
			pushh.reg(pushh.ang);
		else if(h.at(0)=='L')
			pushh.ind(pushh.ang);
		else if((h.at(0)=='V')||(h.at(0)=='I'))
			pushh.volt(pushh.ang);
		else if(h.at(0)=='C')
			pushh.caps(pushh.ang);
		jam.push_back(pushh);
		cout<<"L@"<<endl;
		}
  		}

	}
	}
//cout<<jam.size()<<"\t"<<comp.size()<<"\t"<<endl;
	}
}	
return jam;
}
/* int main()
 {
	int a=20;
 	string h=windowmaker(500,500);
 	string q =ground(225,375,275,375);
	string p = capacitor(245,390);
 	string w=volt(300,280,20);
// 	string z=regester(100,222);
// 	string e=volt(220,222,20);
// 	string i = inductor(100,222);
 	cout<<q<<endl<<p<<endl<<w;
// 	cout<<endl;
// 	cout<<endl;
	
   ofstream myfile;
   myfile.open ("example.svg");
   myfile << h<<endl<<q<<p<<endl<<w<<endl;
   string end = "</svg>";
   myfile<<end;
   myfile.close();	
	
 	return 0;
 }*/
