//
//  main.cpp
//  Laba 2 Cash-Account
//
//  Created by гера on 28.09.16.
//  Copyright © 2016 гера. All rights reserved.
//


//  Клас Cash для роботи з грошовими сумами. Сума повинна бути подана полями-номіналами банкнот і 
//копійок (1, 2, 5, 10, 20, 50 100, 200, 500 гривень; 1, 2, 5, 10, 25, 50 копійок), 
//значенням яких є кількість банкнот даного виду. Наприклад, сума в 135 грн 45 коп. –  
//банкнота в 100 грн. – 1, банкнота в 20 грн. – 1, банкнота в 10 грн. – 1, банкнота в 5 грн. – 1, 
//25 коп. – 1, 10 коп. – 2 (при визначенні номіналів банкнот виходимо з мінімізації їх кількості). 
//Дробова частина під час виведення на екран повинна бути відділена від цілої комою. Реалізувати додавання,
//віднімання, ділення сум, ділення та множення суми на дробове число та операції порівняння.



//  Клас для банківського рахунку Account з полями: прізвище власника, номер рахунку, 
//сума на рахунку, що подана як екземпляр класу відповідно до варіанту завдання, відсоток нарахування. 
//Операції: відкриття рахунку, зняття суми, поповнення рахунку, нарахування відсотків, переведення суми в валюту за 
//заданим курсом Х, отримати суму не в числовому, а в словесному відображенні (наприклад: 121,30 – сто двадцять одна гривня 
//тридцять копійок).



#include <iostream>
#include <cmath>
using namespace std;


class Cash
{
public:
    
    int sum;
    int Grivnu[9] = {1,2,5,10,20,50,100,200,500};
    int kopeyki[6]={1,2,5,10,25,50};
    int SaveGrivna[9]={};
    int SaveKopeyka[6]={};
    int intpart;
    int floatpart;
    int added;
    void getamountofpaper();

    
    Cash operator+(Cash op2);
    Cash operator-(Cash op2);
    Cash operator*(float);
    Cash operator/(float);
    
//    bool operator==(const Cash& left)const;
    
    
    
    
    Cash()
        {
        intpart=floatpart=0;
        for(int i=0; i<=8; i++)SaveGrivna[i]=0;
        for(int i=0; i<=5; i++)SaveKopeyka[i]=0;
        };
  
    
    Cash(float sum):Cash()
    {
    
        int intpart=(*this).intpart=(int)sum;
        int floatpart=(*this).floatpart=(int)(sum*100)%100;
        
        
        ///////////////////////////////////////dva cukla intpart i floatpart
        ///////////////////////////////////////kazduy iz nix budet otnimat kupuru nolsego nominala
        
        for(int i=8; i>=0; i--){
            while (intpart >=Grivnu[i])
            {
                intpart -= Grivnu[i];
                SaveGrivna[i]++;
            }
        }

        for(int i=5; i>=0; i--){
            while (floatpart >=kopeyki[i])
            {
                floatpart -= kopeyki[i];
                SaveKopeyka[i]++;
            }
        }
        
//        for(int i=8; i>=0; i--)
//        {
//            cout << Grivnu[i]<<"\t";
//            cout << SaveGrivna[i]<<"\t"<<"\t";
//        }
//        
//        cout<<"\n";
//        
//        for(int i=5; i>=0; i--)
//        {
//            cout << kopeyki[i]<<"\t";
//            cout << SaveKopeyka[i]<<"\t"<<"\n";
//        }

    };
};


bool operator==(const Cash& first, const Cash& second)
{
    return first.intpart == second.intpart && first.floatpart == second.floatpart;
    
}


bool operator!=(const Cash& first, const Cash& second)
{
    return first.intpart != second.intpart || first.floatpart != second.floatpart;
}

bool operator<(const Cash& first, const Cash& second)
{
    
    
    if (first.intpart<second.intpart)
    {
        return true;
    }
    if (first.intpart>second.intpart)
    {
        return false;
    }
    //else
    
    return first.floatpart<second.floatpart;
    
}


bool operator>(const Cash& first, const Cash& second)
{
    
    return second<first;
    
}


void Cash::getamountofpaper()
{
            for(int i=8; i>=0; i--)
            {
                cout << Grivnu[i]<<"\t";
                cout << SaveGrivna[i]<<"\t"<<"\t";
            }
    
            cout<<"\n";
    
            for(int i=5; i>=0; i--)
            {
                cout << kopeyki[i]<<"\t";
                cout << SaveKopeyka[i]<<"\t"<<"\n";
            }

};



/////malik 791



///////////////////////////////////////////////////// operator cout ++

ostream& operator << (ostream& os,const Cash& cash)
{

    os<< cash.intpart<<","<<cash.floatpart;
    return os;
}

/////////////////////////////////////////////// summa ++
Cash Cash::operator+(Cash op2)
{
    Cash temp;
    

    
    temp.intpart = intpart + op2.intpart;
    
    temp.floatpart = floatpart + op2.floatpart;
    
    if (temp.floatpart > 99) {
        temp.floatpart -=100;
        temp.intpart++;
    }
    
    return temp;
};



Cash Cash::operator*(float f)
{

    float sum=(intpart+floatpart/100.0)*f;

    
    return Cash(sum);
};




Cash Cash::operator/(float f)
{
    
    float sum=(intpart+floatpart/100.0)/f;
    
    
    return Cash(sum);
};

/////////////////////////////////////////////// vuchitanie ++

Cash Cash::operator-(Cash op2)
{
    Cash temp;
    

    temp.intpart = intpart - op2.intpart;
    temp.floatpart = floatpart - op2.floatpart;
    
    
    
    if (temp.floatpart <= 0)
    {
        temp.floatpart+=100;
        temp.intpart--;
    }


    return temp;
};


/////////////////////////////////////////////// sravnenie

//Cash Cash::operator=(Cash op2)
//{
//    Cash temp;
//    
//    
//    return temp;
//};




//bool Cash::operator==(const Cash& amount)const
//{
//    
//    
//    return 0;
//}



class Account
{
    string name;
    int accountNumber;
    Cash howmuchmoney;
    float persent;
    
    public:
    Account(string n, float p=9);
    
    void addmoney(Cash);
    void withdrawmoney(Cash);
    void addpersent();
    void ObminValpok(float s,float pok);
    void ObminValprod(float s,float prod);
};

Account::Account(string n, float p)
{

    name=n;
    
    accountNumber=rand()%100000;
    
    howmuchmoney=Cash(0);
    
    persent=p;
    
    
}

void Account::addmoney(Cash add)
{
    howmuchmoney = howmuchmoney+add;
}

void Account::withdrawmoney(Cash withdraw)
{
    if (withdraw>howmuchmoney)
        {return;}
    
    howmuchmoney = howmuchmoney-withdraw;
}

void Account::addpersent()
{
    howmuchmoney=howmuchmoney*(1+persent/100);
}

void Account::ObminValpok(float s,float pok)
{
    s=s*pok;
}

void Account::ObminValprod(float s,float prod)
{
    s=s*prod;
}


/////construktor vidkrutta raxunku
/////summa cash




int main()
{
    
    
    cout<<"Enter your amount of money(___.__): ";
    float f;
    
    cin>>f;
    
    Cash c(f);
    
    
//    cout << "You have " <<c<<" grivnas on your acount."<<"\n"<<"What you can do:"<< endl;
//    cout << "1.Add money(+)"<<"\n"<<"2.Withdraw money(-)"<<"3.Calculate the percentage(%)";
   
    
  
    
    float s;

    cin>>s;
    
    Cash h(s);
    
    
    if (h>c)
    {
        cout << "fuckyou";
    }
    
    else
    {
         cout << c-h;
    }
  
    h.getamountofpaper();
   
 
    
//    cout<<c<<endl;
    
    
    
    
    
    
//  int Whattodo;
//    cin>>Whattodo;
//    
//    switch (Whattodo) {
//        case 1:
//            <#statements#>
//            break;
//        case 2:
//            <#statements#>
//            break;
//        case 3:
//            <#statements#>
//            break;
//            
//            
//        default:
//            break;
//    }
    
 
    
   

}
