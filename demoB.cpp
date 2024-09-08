#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string strands = "";
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case 'A':
                strands += "T";
                break;
            case 'T':
                strands += 'A';
                break;
            case 'C':
                strands += 'G';
                break;

            default:
                strands += "C";
                break;
            }
        }
        for (int i = strands.length() - 1; i >= 0; i--)
        {
            cout << strands[i];
        }
        cout << endl;
    }

    return 0;
}