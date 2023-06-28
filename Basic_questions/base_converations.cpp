#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int decTObin(int dec)
{
    string dec_str = "";
    while (dec > 0)
    {
        dec_str += to_string(dec % 2);
        dec /= 2;
    }
    reverse(dec_str.begin(), dec_str.end());
    return stoi(dec_str);
}
int decTOoct(int dec)
{
    string oct_str = "";
    while (dec > 0)
    {
        oct_str += to_string(dec % 8);
        dec /= 8;
    }
    reverse(oct_str.begin(), oct_str.end());
    int oct = stoi(oct_str);
    return oct;
}

int binTOdec(string bin)
{
    // int conv = stoi(x);
    int dec = 0;
    for (int i = 0, j = bin.size() - 1; i < bin.size(); i++, j--)
    {
        dec += (bin[i] - '0') * pow(2, j);
    }
    return dec;
}
int binTOoct(string bin)
{
    int dec = binTOdec(bin);
    cerr << dec;
    return decTOoct(dec);
}

int octTOdec(int oct)
{
    string oct_str = to_string(oct);
    int dec = 0;
    for (int i = 0, j = oct_str.size() - 1; i < oct_str.size(); i++, j--)
    {
        dec += (oct_str[i] - '0') * pow(8, j);
    }
    return dec;
}
int octTObin(int oct)
{
    int dec = octTOdec(oct);
    cerr << dec;
    return decTObin(dec);
}

int main()
{

    int dec = 22;
    int bin = 10110;
    int oct = 45;
    string hex = "a46"; // 2630

    // cout << binTOdec(bin) << endl;
    // cout << binTOoct(bin) << endl;

    // cout << decTOoct(dec) << endl;
    cout << decTObin(dec) << endl;

    // cout << octTOdec(oct) << endl;
    // cout << octTObin(oct) << endl;

    return 0;
}