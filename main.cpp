#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

#include "minmax.h"
#include "vectorprint.h"

int gradientDescent(std::vector<float>,std::vector<float>,float, float,float);

int main()
{
    std::vector<int> X{110,140,145,150,160};
    std::vector<int> Y{1991,2245,3319,2140,3312};

    auto Xminmax = minmaxstandard(X);
    auto Yminmax = minmaxstandard(Y);


    float a,b;
    srand(static_cast<uint16_t>(time(0)));

    a = rand()%100;
    b = rand()%100;
    a /= 100;
    b /= 100;

    //a=0.45;
   // b=0.75;

    std::cout << a << " " << b << "\n";

    gradientDescent(Xminmax,Yminmax,a,b,0.001);
/*
    std::vector<float> Ypred(Xminmax.size(),0);
    std::vector<float> SSE(Xminmax.size(),0);
    std::vector<float> dowS_by_dowA(Xminmax.size(),0);
    std::vector<float> dowS_by_dowB(Xminmax.size(),0);

    float SSE_total=0;
    float Aerror_total=0;
    float Berror_total=0;

    for(size_t i=0; i<Xminmax.size();i++)
    {
        Ypred[i] = round(a+b*Xminmax[i]);
        SSE[i] = pow(Yminmax[i]-Ypred[i],2)/2;
        SSE[i] = round(SSE[i]);

        dowS_by_dowA[i] = -((Yminmax[i]-Ypred[i]));
        dowS_by_dowB[i] = -((Yminmax[i]-Ypred[i])*Xminmax[i]);

        dowS_by_dowA[i] = round(dowS_by_dowA[i]);
        dowS_by_dowB[i] = round(dowS_by_dowB[i]);

        SSE_total += SSE[i];
        Aerror_total += dowS_by_dowA[i];
        Berror_total += dowS_by_dowB[i];
    }

    print(Xminmax,Yminmax,Ypred, SSE);
    print(Ypred, SSE,dowS_by_dowA,dowS_by_dowB);
    std::cout << SSE_total << " " << Aerror_total << " " << Berror_total;*/
    return 0;
}
int x;
int gradientDescent(std::vector<float>Xminmax,std::vector<float>Yminmax,float a=0.45, float b=0.75, float r =0.01)
{
int flag=1;

while(flag)
{

    std::vector<float> Ypred(Xminmax.size(),0);
    std::vector<float> SSE(Xminmax.size(),0);
    std::vector<float> dowS_by_dowA(Xminmax.size(),0);
    std::vector<float> dowS_by_dowB(Xminmax.size(),0);

    float SSE_total=0;
    float Aerror_total=0;
    float Berror_total=0;

    for(size_t i=0; i<Xminmax.size();i++)
    {
        Ypred[i] = (a+b*Xminmax[i]);
        SSE[i] = pow(Yminmax[i]-Ypred[i],2)/2;

        SSE_total += SSE[i];

        SSE[i] = (SSE[i]);

        dowS_by_dowA[i] = -((Yminmax[i]-Ypred[i]));
        dowS_by_dowB[i] = -((Yminmax[i]-Ypred[i])*Xminmax[i]);

        dowS_by_dowA[i] = (dowS_by_dowA[i]);
        dowS_by_dowB[i] = (dowS_by_dowB[i]);

        Aerror_total += dowS_by_dowA[i];
        Berror_total += dowS_by_dowB[i];
    }

   // print(Xminmax,Yminmax,Ypred, SSE);
    //print(Ypred, SSE,dowS_by_dowA,dowS_by_dowB);

    float newA = a - r*Aerror_total;
    float newB = b - r*Berror_total;


    float testA = a-newA;
    if(testA<0){testA*=(-1);}

    float testB = b-newB;
    if(testB<0){testB*=(-1);}

    x++;

    std::cout <<"SSE_total = "<< SSE_total << " \ntestA = " << testA <<" \ntestB = " << testB;

    std::endl(std::cout);
    std::cout << "a = " << a;
    std::endl(std::cout);
    std::cout << "b = " << b;
    std::endl(std::cout);
    std::cout << "x = " << x << std::endl;
    std::endl(std::cout);

    if(SSE_total < 0.05 || x > 100000 || testA < r/100000000 || testB < r/100000000) flag=0;
    else
    {
        a = (newA);
        b = (newB);
    }
}

return true;
}
