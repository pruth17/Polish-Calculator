/**
** Name : Pruthvi Punwar

**/


#include <iostream>
#include "Stack.h"
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

bool isNumber(string s);
bool isOperand(string z);

int main()
{
string input;

Stack <string> S1;
Stack<int> S2;

string buffer;
string temp1;
int temp2;
int a1,a2,a3;

    cout << "Welcome!" << endl << endl;

do
{
 stringstream mystream;


    cout << "Please enter an equation in Polish Notation or press q to quit: " ;
getline(cin,input);
    if(input == "Q" || input == "q")
    {
        input = "aa";
    }


    else{
{
mystream.str(input);


while(mystream >> buffer)
{
	S1.push(buffer);
}




while(S1.getSize()!=0 )
{

if(isNumber(S1.peek()))
{
	string q = S1.peek();
	temp2 = atoi(q.c_str());
	S2.push(temp2);
	S1.pop();

}
else if (isOperand(S1.peek()))
	{
		string operand = S1.peek();
		S1.pop();
		if(operand=="*")
		{
			 a1 = S2.peek();
			S2.pop();
			 a2 = S2.peek();
			S2.pop();

			a3 = a1*a2;
			S2.push(a3);
		}
		else if (operand=="+")
				 {
					  a1 = S2.peek();
					 S2.pop();
					  a2 = S2.peek();
					 S2.pop();

					 a3 = a1+a2;
					 S2.push(a3);
				 }
		else if(operand=="-")
		{
			 a1 = S2.peek();
			S2.pop();
			 a2 = S2.peek();
			S2.pop();

			a3 = a1-a2;
			S2.push(a3);
		}
		else
		{
			 a1 = S2.peek();
			S2.pop();
			 a2 = S2.peek();
			S2.pop();

			a3 = a1/a2;
			S2.push(a3);
		}


	}

}


   


    cout << "The answer is: " << S2.peek() << endl << endl;
    S2.pop();
}

    }

}
    while(input != "aa");

    cout << endl;
    cout << "GoodBye!" << endl << endl;


    return 0;
}




bool isNumber(string s)
{
for(int i=0;i<s.length();i++)
{
	if(s[i]>=48 && s[i]<=57)
		return true;
}
return false;
}

bool isOperand(string a)
{
for (int c=0;c<a.length();c++)
{
	if(a[c]>=42 && a[c]<=47)
		return true;
}
return false;
}




