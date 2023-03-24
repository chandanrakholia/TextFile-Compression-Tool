#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <string>
#include <map>
#include <string>
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
    int cnt;
    string str = "";
    Node *right = NULL;
    Node *left = NULL;
};
class comparator
{
public:
    bool operator()(Node *a, Node *b)
    {
        if (a->cnt == b->cnt)
        {
            a->data < b->data;
        }
        return a->cnt > b->cnt;
    }
};
void generatebinarycode(Node *root, string s)
{
    if (root->right == NULL and root->left == NULL)
    {
        root->str = s;
        return;
    }
    generatebinarycode(root->left, s + "0");
    generatebinarycode(root->right, s + "1");
}
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
void solve(string finName, string pass)
{
    pBar bar;
    for (int i = 0; i < 10; i++)
    {
        bar.update(1);
        bar.print();
    }
    string foutName = finName.substr(0, finName.length() - 4) + ".dat";
    ifstream fin;
    fin.open(finName);
    unordered_map<int, int> mp;
    char c;
    while (fin.get(c))
    {
        mp[int(c)]++;
    }
    mp[32]++;    //adding extra character to prevent from infine loop;
    fin.close();
    vector<Node *> v;
    for (auto itr : mp)
    {
        Node *newNode = new Node();
        newNode->data = itr.first;
        newNode->cnt = itr.second;
        v.push_back(newNode);
    }
    priority_queue<Node *, vector<Node *>, comparator> pq;
    for (auto i : v)
    {
        pq.push(i);
    }
    for (int i = 0; i < 20; i++)
    {
        bar.update(1);
        bar.print();
    }
    priority_queue<Node *, vector<Node *>, comparator> temppq = pq;
    Node *newNode;
    int cnt = 0;
    while (temppq.size() != 1)
    {
        newNode = new Node();
        newNode->cnt = temppq.top()->cnt;
        newNode->left = temppq.top();
        temppq.pop();
        newNode->cnt += temppq.top()->cnt;
        newNode->right = temppq.top();
        temppq.pop();
        temppq.push(newNode);
    }
    Node *root = newNode;
    generatebinarycode(root, "");
    map<int, string> codetable;
    for (auto i : v)
    {
        codetable[i->data] = i->str;
    }
    for (int i = 0; i < 10; i++)
    {
        bar.update(1);
        bar.print();
    }
    string en;
    string temp;
    en += pass;
    en += char(0 + pq.size());
    for (auto i : codetable)
    {
        en += char(i.first);
        temp.assign(127 - i.second.length(), '0');
        temp += "1";
        temp += i.second;
        for (int j = 0; j < 16; j++)
        {
            en += char(bintodec(temp.substr(0, 8)));
            temp = temp.substr(8);
        }
    }
    for (int i = 0; i < 20; i++)
    {
        bar.update(1);
        bar.print();
    }
    temp = "";
    char ch;
    fin.open(finName, ios::in);
    while (fin.get(ch))
    {
        temp += codetable[int(ch)];
        while (temp.length() > 8)
        {
            en += char(bintodec(temp.substr(0, 8)));
            temp = temp.substr(8);
        }
    }
    for (int i = 0; i < 20; i++)
    {
        bar.update(1);
        bar.print();
    }

    int zero = 8 - temp.length();
    if (temp.length() < 8)
    {
        temp.append(zero, '0');
    }
    en += char(bintodec(temp));
    en += char(zero);
    fstream fout;
    fout.open(foutName, ios::binary | ios::out);
    fout.write(en.c_str(), en.size());
    fin.close();
    fout.close();
    for (int i = 0; i < 20; i++)
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
            cout << "your encrypted password is: " << argv[2] << endl;
            cout << "compression done! output file name is: " << fileName.substr(0, fileName.length() - 4) << ".dat" << endl;
            exit(0);
        }
        else if (argc == 2)
        {
            pass = "    ";
            solve(fileName, pass);
            cout << endl;
            cout << "compression done! output file Name:" << fileName.substr(0, fileName.length() - 4) << ".dat" << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Your Arguments are not valid:";
        exit(1);
    }
}