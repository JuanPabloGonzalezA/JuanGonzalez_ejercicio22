#include <iostream>
#include <math.h>
using namespace std;

double gauss(double mean, double sigma, double x);

double gauss(double mean, double sigma, double x)
{
	return exp(-pow((x-mean)/sigma,2)/2.0);
}
int main()
{
	double D = 1.0;
	double dx=0.01;
	double dt = 0.00001;
	double Xmin=0;
	double Xmax=2;
	int Nx=((Xmax-Xmin)/dx)+1;
	
	double *uxtnew, *uxtold,*uxtinicial;
	uxtnew = new double[Nx];
	uxtold = new double[Nx];
	uxtinicial = new double[Nx];
	
	double x=0;
	
	int i;
	int j;

	//inicializacion
	uxtold[0]=0;
	uxtold[Nx-1]=0;
	for(i=1;i<Nx-1;i++)
	{
		x=i*dx;
		uxtold[i]=gauss(1.0,0.1,x);
		cout<<0<<" "<<x<<" "<<uxtold[i]<<endl;
	}
	int mitad = Nx/2;
	while(uxtold[mitad]>0.5)
	{
		uxtnew[0]=0;
		uxtnew[Nx-1]=0;
		for(i=1;i<Nx-1;i++)
		{
			uxtnew[i]= D*dt*(uxtold[i+1]+uxtold[i-1]-2*uxtold[i])/(dx*dx) +uxtold[i];
		}
		for(i=0;i<Nx;i++)
		{
			uxtold[i]=uxtnew[i];
		}
	}
	
	for(i=0;i<Nx;i++)
	{
		x=i*dx;
		cout<<1<<" "<<x<<" "<<uxtnew[i]<<endl;
	}
	return 0;
}
