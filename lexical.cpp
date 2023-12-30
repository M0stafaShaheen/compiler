#include<bits/stdc++.h>
using namespace std;

bool IsKeyword(string str)
{
	if (str == "if"||str ==  "else" ||
        str == "while" || str == "do" ||
        str == "break" || str == "continue"||
        str== "int" || str == "double"||
        str=="float" ||str== "return"||
        str== "char" || str== "case"||
        str== "long" || str=="short"||
        str== "typedef" || str== "switch"||
        str== "unsigned" || str== "void"||
        str=="static" || str=="struct"||
        str== "sizeof" ||str=="long"||
        str== "volatile"|| str== "typedef"||
        str== "enum" || str== "const"||
        str== "union" || str== "extern"||
        str=="bool")
        {
            return true;
        }
    else
    {
       return false;
    }
}

bool IsSemicolon(string str)
 { 
 if(str == ";") { 
 return true ; 
 }
 return false ; 
 }
 
bool IsAssignment (string str)
{ 
 if(str == "=") { 
 return true ; 
 }
 return false ; 
}

bool IsOperator(string str)
{
	if(str == ">"  || str == "<"
	||str == "/" || str == "+" ||
	str =="-" || str == "|" ||
	str == "&" || str == "*"
	) { 
	return true ; 
	}
	return false ; 
}
bool IsNumber(string str) { 
    	char c = str[0] ; 
    	int n = c - '0' ; 
    	if(n >=0 && n <=9 ) { 
    	return true ; 
		}
		return false ; 
}

bool SpecialCharacter(string str) { 
	if(str =="." || str == "()" || str =="(" || str == ")"
	|| str == ":" || str =="," || str ==";"  
	) { 
	return true;
	}
	return false ; 
}

void check(string str)
{
	int left=0;
	int right = 0 ;
	int length = str.length();
	while(right <= length)
	{
		int c = 0  ; 
		while(str[right]!=' ')
		{
			c++ ; 
			right++;
		}
		string sub = str.substr(left , c);
		if(IsKeyword(sub) == true){
			cout<<"key word     ("<<sub<<")\n"; 
		}
		else if(IsSemicolon(sub) == true) { 
			cout<<"semicolon    ("<<sub<<")\n" ; 
		}
		else if(IsAssignment(sub) == true)
	    { 
	    	cout<<"assignment   ("<<sub<<")\n" ; 
		}
		else if(IsOperator(sub) == true)
	    {
	    	cout<<"operator     ("<<sub<<")\n"; 
		}
		else if(IsNumber(sub) == true)
		{
			cout<<"IsNumber     ("<<sub<<")\n" ;  
		}
		else if(SpecialCharacter(sub) == true)
		{
			cout<<"SpecialCharacter     ("<<sub<<")\n"; 
		}
		else { 
		    cout<<"Identifier   ("<<sub<<")\n" ; 
		}
		right++;
		left = right ;		 
	}
}
 
int main()
{
	
	string str = "int x = 2 + 3 ;" ;  
	check(str);
	
	return 0;
}
