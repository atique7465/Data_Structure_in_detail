/// resource 01: https://www.youtube.com/watch?v=vq-nUF0G4fI&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=21
/// resource 02: https://gist.github.com/mycodeschool/7867739

#include<bits/stdc++.h>
using namespace std;

map<char,int>precedence;

bool isOperator(char ch)
{
    return ch=='+' || ch=='-' || ch=='*' || ch=='/';
}

bool isOperand(char ch)
{
    return ch>='0' && ch<='9';
}

bool isOpeningBracket(char ch)
{
    return ch=='(' || ch=='{' || ch=='[';
}

bool isClosingBracket(char ch)
{
    return ch==')' || ch=='}' || ch==']';
}

bool hasHigherPrecedence(char a, char b)
{
    return precedence[a]>precedence[b];
}

string infix_To_postfix(string infix)
{
    string postfix="";
    stack<char>s;

    for(int i=0; i<infix.size(); i++)
    {
        if(infix[i]==' ' || infix[i]==',')
            continue;

        else if(isOperator(infix[i]))
        {
            while(!s.empty() && !isOpeningBracket[s.top()] && hasHigherPrecedence(s.top(),infix[i]))
            {
                postfix+="_";
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
        }

        else if(isOperand(infix[i]) || infix[i]=='.')
        {
            postfix+="_";
            while(isOperand(infix[i]) || infix[i]=='.')
            {
                postfix+=infix[i];
                i++;
            }
            i--;
        }

        else if(isOpeningBracket(infix[i]))
            s.push(infix[i]);

        else if(isClosingBracket(infix[i]))
        {
            while(!s.empty() && !isOpeningBracket(s.top()))
            {
                postfix+="_";
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while(!s.empty())
    {
        postfix+="_";
        postfix+=s.top();
        s.pop();
    }

    return postfix.substr(1,postfix.size()-1);
}

int main()
{
    precedence['+']=1;
    precedence['-']=1;
    precedence['*']=2;
    precedence['/']=2;

    string infix;
    cout<<"Enter the infix expression : ";
    cin>>infix;

    cout<<endl<<"Resultant of PostFix expression is : ";
    cout<<infix_To_postfix(infix);
    cout<<endl;

    return 0;
}

/*
input1: 3+{(5+9)*2}
res: 3_5_9_+_2_*_+

input2: 31+{(52+9.8)*2.5}
res:
*/
