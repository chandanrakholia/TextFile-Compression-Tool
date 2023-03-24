#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
using namespace std;
class pBar
{
public:
    void update(double newProgress)
    {
        currentProgress += newProgress;
        amountOfFiller = (int)((currentProgress / neededProgress) * (double)pBarLength);
    }
    void print()
    {
        currUpdateVal %= pBarUpdater.length();
        cout << "\r"
             << firstPartOfpBar;
        for (int a = 0; a < amountOfFiller; a++)
        {
            cout << pBarFiller;
        }
        cout << pBarUpdater[currUpdateVal];
        for (int b = 0; b < pBarLength - amountOfFiller; b++)
        {
            cout << " ";
        }
        cout << lastPartOfpBar
             << " (" << (int)(100 * (currentProgress / neededProgress)) << "%)"
             << flush;
        currUpdateVal += 1;
    }
    std::string firstPartOfpBar = "Progress: [",
                lastPartOfpBar = "]",
                pBarFiller = "#",
                pBarUpdater = "#";

private:
    int amountOfFiller,
        pBarLength = 50,
        currUpdateVal = 0;
    double currentProgress = 0,
           neededProgress = 100;
};
void progress(int n)
{
    pBar bar;
    for (int i = 0; i < 105; i++)
    {
        bar.update(1);
        bar.print();
    }
}
class Node
{
public:
    int data;
    string str = "";
    Node *right = NULL;
    Node *left = NULL;
};
int bintodec(string s)
{
    int res = 0;
    int base = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] - '0')
        {
            res += base;
        }
        base *= 2;
    }
    return res;
}
string dectobin(int inNum)
{
    string temp = "", res = "";
    while (inNum > 0)
    {
        temp += (inNum % 2 + '0');
        inNum /= 2;
    }
    res.append(8 - temp.length(), '0');
    for (int i = temp.length() - 1; i >= 0; i--)
    {
        res += temp[i];
    }
    return res;
}
void solve(string finName, string pass)
{
    pBar bar;
    for (int i = 0; i < 10; i++)
    {
        bar.update(1);
        bar.print();
    }
    string foutName = finName.substr(0, finName.length() - 4) + "_uncompressed.txt";
    ifstream fin;
    fin.open(finName, ios::in | ios::binary);
    string password = "";
    unsigned char pc;
    fin.read(reinterpret_cast<char *>(&pc), 1);
    password.push_back(char(int(pc)));
    fin.read(reinterpret_cast<char *>(&pc), 1);
    password.push_back(char(int(pc)));
    fin.read(reinterpret_cast<char *>(&pc), 1);
    password.push_back(char(int(pc)));
    fin.read(reinterpret_cast<char *>(&pc), 1);
    password.push_back(char(int(pc)));
    if (pass != password)
    {
        cout << password << endl;
        cout << "Incorrect password" << endl;
        exit(1);
    }
    for (int i = 0; i < 10; i++)
    {
        bar.update(1);
        bar.print();
    }
    unsigned char size;
    fin.read(reinterpret_cast<char *>(&size), 1);
    map<string, char> table;
    for (int i = 0; i < size; i++)
    {
        unsigned char ch;
        unsigned char code[16];
        fin.read(reinterpret_cast<char *>(&ch), 1);
        fin.read(reinterpret_cast<char *>(&code), 16);
        string str = "";
        for (int j = 0; j < 16; j++)
        {
            str += dectobin(int(code[j]));
        }
        int k = 0;
        while (str[k] == '0')
        {
            k++;
        }
        str = str.substr(k + 1);
        table[str] = int(ch);
    }
    Node *root = new Node;
    Node *R = root;
    for (auto i : table)
    {
        string code = i.first;
        Node *r = R;
        for (int j = 0; j < code.length(); j++)
        {
            Node *temp = new Node;
            if (code[j] == '0')
            {
                if (r->left == NULL)
                {
                    r->left = temp;
                }
                r = r->left;
            }
            else if (code[j] == '1')
            {
                if (r->right == NULL)
                {
                    r->right = temp;
                }
                r = r->right;
            }
            if (j == code.length() - 1)
            {
                r->str = code;
                r->data = int(i.second);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        bar.update(1);
        bar.print();
    }
    ofstream fout;
    fout.open(foutName, ios::out);
    string temp;
    unsigned char c;
    fin.read(reinterpret_cast<char *>(&c), 1);
    while (!fin.eof())
    {
        temp += dectobin(int(c));
        fin.read(reinterpret_cast<char *>(&c), 1);
    }
    for (int i = 0; i < 20; i++)
    {
        bar.update(1);
        bar.print();
    }
    int zero = bintodec(temp.substr(temp.length() - 8));
    temp = temp.substr(0, temp.length() - 8);
    string last8 = temp.substr(temp.length() - 8);
    temp = temp.substr(0, temp.length() - 8);
    last8 = last8.substr(0, last8.length() - zero);
    temp = temp + last8;
    for (int i = 0; i < 10; i++)
    {
        bar.update(1);
        bar.print();
    }
    int j = 0;
    string sub;
    Node *node = R;
    while (j < temp.size())
    {
        if (temp[j] == '0')
        {
            node = node->left;
        }
        else if (temp[j] == '1')
        {
            node = node->right;
        }
        if (node->right == NULL and node->left == NULL)
        {
            fout << char(node->data);
            node = R;
        }
        j++;
    }
    fin.close();
    fout.close();
    for (int i = 0; i < 40; i++)
    {
        bar.update(1);
        bar.print();
    }
}
int main(int argc, char *argv[])
{
    if (argc == 2 || argc == 3)
    {

        string fileName = argv[1];
        string pass;
        if (argc == 3)
        {
            pass = argv[2];
            solve(fileName, pass);
            cout << endl;
            cout << "Decompression done! output file name is: " << fileName.substr(0, fileName.length() - 4) << ".txt" << endl;
            exit(0);
        }
        else if (argc == 2)
        {
            pass = "    ";
            solve(fileName, pass);
            cout << endl;
            cout << "Decompression done! output file Name:" << fileName.substr(0, fileName.length() - 4) << ".txt" << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Your Arguments are not valid:";
        exit(1);
    }
}