#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>

using namespace std;

/*											1
struct tocka2D
{
    float x;
    float y;
};
struct tocka3D
{
    float x;
    float y;
    float z;
};

float kvadrat(float a)
{
    return a*a;
}

float rastojanie(tocka2D a, tocka2D b)
{
    return sqrt(kvadrat(b.x-a.x)+kvadrat(b.y-a.y));
}

float rastojanie3D(tocka3D a, tocka3D b)
{
    return sqrt(kvadrat(b.x-a.x)+kvadrat(b.y-a.y)+kvadrat(b.z-a.z));
}

int ista_prava(tocka2D a, tocka2D b, tocka2D c)
{
    if (c.y-a.y==((b.y-a.y)/(b.x-a.x))*(c.x-a.x))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(){
    float x1, y1, x2, y2;
    cin>>x1>>y1;
	cin>>x2>>y2;
	tocka2D t1 = { x1, y1 };
	tocka2D t2 = { x2, y2 };
	cout<<rastojanie(t1, t2);
    float z1, z2;
    cin>>z1>>z2;
    tocka3D t3 = {x1, y1, z1};
    tocka3D t4 = {x2, y2, z2};
    cout<<rastojanie3D(t3, t4);
    tocka2D t5 = {z1, z2};
    cout<<ista_prava(t1, t2, t5)<<endl;
	return 0;
}
*/

/*												3
struct proizvod{
	char ime[20];
	int cena;
	int kolicina;
};

int main(){
	proizvod x[50];
	int n,i,sum=0;
	cin>>n;
	for(i = 0; i<n ; i++){
		cin>>x[i].ime;
		cin>>x[i].cena;
		cin>>x[i].kolicina;
	}
	for(i = 0; i<n ; i++){
		cout<<i+1<<x[i].ime <<"\t"<<x[i].cena<<"x"<<x[i].kolicina<<"="<<x[i].cena * x[i].kolicina<<endl;
		sum += x[i].cena * x[i].kolicina;
	}
	cout<<sum;
}
*/