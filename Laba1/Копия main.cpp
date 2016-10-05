//
//  main.cpp
//  Laba1-2
//
//  Created by гера on 19.09.16.
//  Copyright © 2016 гера. All rights reserved.
//


#include "iostream"
using namespace std;




class Laba1
{
public:

   
    int intPart;        // целая часть
    int numerator;      // числитель
    int denominator;    // знаменатель
public:
    void GetMixedView();        //смешанный вид
    void Sokr();                //сокращение дроби
    void GetIntPart();          //выделение целой части

    friend ostream& operator << (ostream&, Laba1&);
//    friend istream& operator >> (istream&, Laba1&);
    
    Laba1();
    Laba1(int, int, int = 0);
 
};

void Laba1::GetMixedView()
{
    GetIntPart();
    Sokr();
}

void Laba1::GetIntPart()
{
    if(numerator >= denominator)
    {
        intPart += (numerator / denominator);
        numerator %= denominator;
    }
    cout << intPart << endl;
    
}


void Laba1::Sokr()
{
    if(numerator != 0)
    {
        int m = denominator,
        n = numerator,
        ost = m%n;
        // вычисление НОД(числитель, знаменатель)
        // алгоритмом Евклида
        while(ost != 0)
        {
            m = n; n = ost;
            ost = m % n;
        }
        int nod = n;
        if(nod != 1)
        {
            numerator /= nod; denominator /= nod;

        }
        cout <<" "<< numerator <<"/"<<denominator<<endl;
    }

}


Laba1 operator + (Laba1 d1,Laba1 d2)
{
//    Laba1 d3;
    
    int numerator = (d1.numerator * d2.denominator + d2.numerator * d1.denominator);
    int denominator = (d1.denominator * d2.denominator);
    int intpart=d1.intPart+d2.intPart;
    
//   cout <<" "<< d3.numerator <<"/"<<d3.denominator<<endl;
    
    return Laba1(numerator,denominator,intpart);
}

ostream& operator << (ostream& out,Laba1& a)
{
//if (a.sign<0)
//{out<<"-";}
    
if (a.intPart != 0)
{out<<a.intPart<<" ";}

if (a.numerator !=0)
{out <<a.numerator<<"/"<<a.denominator;}
    
if (a.intPart == 0 && a.numerator==0)
{out<<"0";}

    return out;
};

Laba1::Laba1()
{
    intPart = 0;
    numerator = 0;
    denominator = 1;
   
}

Laba1::Laba1(int n, int d, int i)
{
    numerator = n;
    denominator = d;
    intPart = i;
   
 
    GetMixedView();
}
int main(){
    
    Laba1 d0(3,6,0);
    
    Laba1 d1(6,9,0);
    
    Laba1 d2(10,4);
    
    
    Laba1 d3 =  d1 +  d2;
    

};