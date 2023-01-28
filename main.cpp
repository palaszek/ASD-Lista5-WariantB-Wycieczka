#include <iostream>

using namespace std;

int n, m, sptr;
int *S;

struct Ulica
{
    int a, b, l, s;
    bool visited = false;
};

int *Sasiedzi(int v, Ulica ulice[])
{
    int *sasiedzi = new int[m];
    for(int i = 0; i < m; i++)
        sasiedzi[i]=-1;
    for(int i = 0; i < m; i++)
    {
        if(ulice[v].a == ulice[i].a || ulice[v].b == ulice[i].b || ulice[v].a == ulice[i].b || ulice[v].b == ulice[i].a)
        {
            sasiedzi[i] = i;;
        }
    }
    return sasiedzi;
}

void DFSEuler ( int v, Ulica ulice[] )
{
    int i;
    int *sasiedzi = Sasiedzi(v,ulice);
    for( i = 0; i < m; i++ )
    {
        if(i == sasiedzi[i] && !ulice[i].visited)
        {
            ulice[i].visited = true;
            DFSEuler ( i, ulice );

        }
    }
    S [ sptr++ ] = v;
    delete [] sasiedzi;
}

int main( )
{
    int i;
    int suma_zadowolenia =0;

    cin >> n;

    m = 2*n;

    Ulica ulice[m];
    S = new int [ m + 1 ];
    sptr = 0;

    for( i = 0; i < m; i++ )
    {
        cin >> ulice[i].a >> ulice[i].b >> ulice[i].l>> ulice[i].s;
        suma_zadowolenia+=(ulice[i].s - ulice[i].l);
    }
    system("CLS");
    if(suma_zadowolenia<0)
    {
        cout << "NIE";
        exit(0);
    }
    else cout << "TAK";

    cout << endl;

    DFSEuler ( 0, ulice );

    int zadowolenie = ulice[S[0]].s;
    int punkt_startowy;
    for(i=1; i<m; i++)
    {
        zadowolenie -= ulice[S[i]].l;
        if(zadowolenie < 0)
        {
            punkt_startowy = i;
            break;
        }
        else
        {
            zadowolenie += ulice[S[i]].s;
        }
    }
    cout<< S[punkt_startowy]+1 << " ";
    if(ulice[S[punkt_startowy]].a == ulice[S[punkt_startowy+1]].a)
        cout << ulice[S[punkt_startowy]].a;
    else if(ulice[S[punkt_startowy]].b == ulice[S[punkt_startowy+1]].b)
        cout << ulice[S[punkt_startowy]].b;
    else if(ulice[S[punkt_startowy]].a == ulice[S[punkt_startowy+1]].b)
        cout << ulice[S[punkt_startowy]].a;
    else if(ulice[S[punkt_startowy]].b == ulice[S[punkt_startowy+1]].a)
        cout << ulice[S[punkt_startowy]].b;

    cout << endl;
    for(i=punkt_startowy+1; i<m; i++)
        cout << S[i]+1 << endl;
    for(i=0; i<punkt_startowy; i++)
        cout << S[i]+1 << endl;

    delete [ ] S;

    return 0;
}
