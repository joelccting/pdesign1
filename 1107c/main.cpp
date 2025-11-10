#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    //io speed up
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> stk;
    int err = 0;

    string s;

    cin >> s;

//    for (int i = 0; i < s.size(); ++i) cout << s[i];
//    cout << endl;

    int size = s.size(), i = 0;
    while (i < size)
    {
        switch (s[i])
        {
        case '(':
        case '[':
        case '{':
            stk.push(s[i]);
            break;

        case ')':
            if (stk.size() == 0)
            {
                err = 1;
            }
            else
            {
                if (stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    err = 1;
                }
            }

            break;

        case ']':
            if (stk.size() == 0)
            {
                err = 1;
            }
            else
            {
                if (stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    err = 1;
                }
            }

            break;

        case '}':
            if (stk.size() == 0)
            {
                err = 1;
            }
            else
            {
                if (stk.top() == '{')
                {
                    stk.pop();
                }
                else
                {
                    err = 1;
                }
            }
            break;

        default:
            break;
        }


//        if ((stk.size() == 0) && (s.size() != 0))
//            err = 1;

        if (err == 1) break;

        ++i;
    }

    if (stk.size() != 0) err = 1;

    if (err) cout << "0";
    else cout << "1";

    return 0;
}
