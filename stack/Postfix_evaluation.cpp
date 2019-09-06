/// resource 01: https://www.youtube.com/watch?v=MeRb_1bddWg&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=20
/// resource 02: https://gist.github.com/mycodeschool/7702441

#include<bits/stdc++.h>
using namespace std;

double Apply_Operator(char op, double v2, double v1)
{
    if(op=='+')
        return v2+v1;
    else if(op=='-')
        return v2-v1;
    else if(op=='*')
        return v2*v1;
    else
        return v2/v1;
}

bool isOperator(char ch)
{
    return ch=='+' || ch=='-' || ch=='*' || ch=='/';
}

double evaluate(string postfix)
{
    stack<double>s;
    for(int i=0; i<postfix.size(); i++)
    {
        if(postfix[i]==' '||postfix[i]=='_')
            continue;
        else if(isOperator(postfix[i]))
        {
            double v1 = s.top();
            s.pop();
            double v2 = s.top();
            s.pop();
            s.push(Apply_Operator(postfix[i],v2,v1));
        }
        else
        {
            double operand = 0.0;
            int ck=0;
            double g = 10.0;
            while(i<postfix.size() && postfix[i]!='_')
            {
                if(postfix[i]=='.')
                    ck=1;
                else if(ck==0)
                    operand = (operand*10) + (postfix[i]-'0');
                else
                {
                    operand = ((operand*g) + (postfix[i]-'0'))/g;
                    g*=10;
                }
                i++;
            }
            s.push(operand);
        }
    }
    return s.top();
}

int main()
{
    string postfix;
    cout<<"Enter the postfix expression : ";
    cin>>postfix;

    cout<<endl<<"Result of evaluation is : ";
    cout<<evaluate(postfix);
    cout<<endl;

    return 0;
}

/*
input1: 31_52_9.3_+_2.5_*_+
res: 184.25

input2: 3_5_9_+_2_*_+
res: 31
*/
