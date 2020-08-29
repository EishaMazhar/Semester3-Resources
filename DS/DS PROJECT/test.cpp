#include<iostream>
using namespace std;
class t{
	public:
		float a[2];
		t(float c,float d)
		{
			a[0]=c;
			a[1]=d;
			cout<<a[1];
		}
};

int main()
{
	t p(0.1,0.2);
}
