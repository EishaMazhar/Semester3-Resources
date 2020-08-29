#include<bits/stdc++.h> 

using namespace std;
int precedence(char ch)
{
	if(ch=='+'|| ch=='-')
		return 1;
	else if(ch=='*'|| ch=='/')
		return 2;
	else if(ch=='^')
		return 3;
	else
		return -1;
}
string ItP(string str)
{
	stack<char> s;
	int l=str.length();
	s.push('x');
	string sout;
	for(int i=0;i<l;i++){
		
		if(isdigit(str[i])!=0){
			sout+=str[i];
		}
		
		else if((str[i]>='a'&& str[i]<='z')||(str[i]>='A'&& str[i]<='Z')){
			sout+=str[i];
		}
		
		
		else if(str[i]=='(')
		{
			s.push('(');
		
		}
		else if(str[i]==')')
		{
			while(s.top()!='x'&&s.top()!='(')
			{
				char temp=s.top();
				s.pop();
				sout+=temp;
			}
			if(s.top()=='(') 
            { 
                char temp=s.top(); 
                s.pop();
            } 
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*'||str[i]=='^')
		{
			while((s.top()!='x')&&(precedence(str[i])<=precedence(str[s.top()]))){
				char temp=s.top();
				s.pop();
				sout+=temp;
			}
			s.push(str[i]);
		}	
	}
	cout<<endl;
	while(s.top()!='x') 
	    { 
	        char c=s.top(); 
	        s.pop(); 
	        sout+=c; 
	    } 
	return sout;
	
}

int evaluateEXP(string sout){
/*	stack<char> stack;
	for(int i=0;sout[i]!='\0';i++){
		if(sout[i]=='*'){
			int x=stack.pop();
			int y=stack.pop();
			stack.push(x*y);
		}
		
		if(sout[i]=='+'){
			int x=stack.pop();
			int y=stack.pop();
			stack.push(x+y);
		}
		
		if(sout[i]=='-')
		{
			int x=stack.pop();
			int y=stack.pop();
			stack.push(x-y);
		}
		
		if(sout[i]=='/'){
			int x=stack.pop();
			int y=stack.pop();
			stack.push(x/y);
		}
		
		if(sout[i]=='^'){
			int x=stack.pop();
			int y=stack.pop();
			stack.push(x^y);
		}
	}
	return stack.pop();*/
}
int main()
{
	cout<<"Enter string :\n";
	string s;
	cin>>s;
	string sout=ItP(s);
	ofstream outfile;
	outfile.open("A2 Q2.txt");
	outfile<<sout<<endl;
	return 0;
}
