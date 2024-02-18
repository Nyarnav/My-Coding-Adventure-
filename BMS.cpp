#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
using std::fixed;
using std::setprecision;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::getline;
class BusinessMath{
    private:
    double P, I, FV, m, r, tmonth, tyear, t, total, A, rm, tm;
    int choice;
    bool warning = false;
    public:
    void BMS(){
        
        
        cout << "\n*****************************************************************\n\n";
            
        cout << "                    *BUSINESS MATH SOLVER*                ";
        cout << "\n\n\n*****************************************************************\n\n";
        if ( warning == true ){
            cout << "\n\n      !!!!!!!!🤬PLEASE CHOOSE ONLY [ 1 ] AND [ 2 👹]!!!!!!!!                 \n\n";
            warning = false;
        }
        cout << "[ 1 ] for simple interest, [ 2 ] for compound interest \n";
        cout << "your choice: ";
        
        cin >> choice;
        
        switch( choice ){
            case 1:
            simpleInt();
            break;
            case 2:
            compoundInt();
            break;
            default:
            warning = true;
            BMS();
            
            break;
        }     
    }
    void simpleInt(){
        cout << "\n**SIMPLE INTEREST**\n";
        cout << "\nchooce the available formula you want to use: \n";
        cout << "\n1.) P = I/rt\n";
        cout << "2.) I = Prt\n";
        cout << "3.) r = I/Pt\n";
        cout << "4.) t = I/Pr\n";
        cout << "5.) A = P (1+ rt)\n";
        cout << "\n";
        cout << "enter your choice here: ";
        cin >> choice;
        cout << "\n\nGIVEN: \n";
        switch ( choice ){
            case 1:
            cout << "\n\nenter the value of I: ";
            cin >> I;
            cout << "\nenter the value of r: ";
            cin >> r;
            
            cout << "enter the value of year and month [ t ]: \n";
            cout << "year/s: ";
            cin >> tyear;
            cout << "tmonth/s: ";
            cin>> tmonth;
            r  = r / 100;
            tmonth = tmonth / 12;
           t = tmonth + tyear;
           cout << "\n\n [ FORMULA ]\n";
           cout << "\n\nP = I/rt\n";
           cout << "P = "<< I <<"/"<< " (" << r  <<") ("<< t <<")\n"; 
            total = r * t;
             
            total = total * 1000;
            total = floor(total);
            total = total / 1000;
            cout << "P = " << I <<" / "<< total << "\n"; 
            P = I / total;
            
            
            cout << "P = " << P;
            cout << "\n";
            return BMS();
            break;
            case 2:
            cout << "\nenter the value of P: ";
            cin >> P;
            cout << "\nenter the value of r: ";
            cin >> r;
            cout << "enter the value of year and month [ t ]: \n";
            cout << "year/s: ";
            cin >> tyear;
            cout << "tmonth/s: ";
            cin>> tmonth;
            r  = r / 100;
            tmonth = tmonth / 12;
            t = tyear + tmonth;
            cout << "\n\n [ FORMULA ]\n";
            cout << "\n\nI = Prt\n";
            cout << "I = " << " ("<< P << ") (" << r << ") (" << t << ")\n";
            I = P * t * r;
            
            
            cout << "I = " << I;
            return BMS();
            break;
            case 3:
            cout << "\n\nenter the value of I: ";
            cin >> I;
            cout << "\nenter the value of P: ";
            cin >> P;
            cout << "enter the value of year and month [ t ]: \n";
            cout << "year/s: ";
            cin >> tyear;
            cout << "tmonth/s: ";
            cin>> tmonth;
            tmonth = tmonth / 12;
            t = tyear + tmonth;
            cout << "\n\n [ FORMULA ]";
            cout << "\n\nr = I/Pt\n";
            cout << "\nr = " << I << "/"<< "(" << P << ")(" << t << ")\n";
            total = P * t;
            total = total * 1000;
            total = floor(total);
            total = total / 1000;
            cout << "r = " << I <<" / "<< total << "\n"; 
            r = I / total;
            
            
            r = r * 100;
            cout << "\nr = " << r << "%\n";
            return BMS();
            break;
            case 4:
            cout << "\n\nenter the value of I: ";
            cin >> I;
            cout << "\nenter the value of P: ";
            cin >> P;
            cout << "\nenter the value of r: ";
            cin >> r;
            r  = r / 100;
            total = P * r;
            total = total * 1000;
            total = floor(total);
            total = total / 1000;
            cout << "\n\n [ FORMULA ]";
            cout << "\nt = I/Pr\n";
            cout << "t = " << I << "/" << "("<<P<< ")("<< r << ")\n";
            cout << "t = " << I << "/" << total;
            t = I / total;
            t = t * 12;
            cout << "\n t = " << t << " year/s\n";
            
            return BMS();
            break;
            case 5:
            cout << "\nenter the value of A: ";
            cin >> A;
            cout << "\nenter the value of r: ";
            cin >> r;
            r  = r / 100;
            cout << "enter the value of year and month [ t ]: \n";
            cout << "year/s: ";
            cin >> tyear;
            cout << "tmonth/s: ";
            cin>> tmonth;
            tmonth = tmonth / 12;
            t = tyear + tmonth;
            total = r * t;
            cout << "\n\n [ FORMULA ]";
            cout << "\nA = P (1+rt)\n";
            cout << A << " = P [1+" << "(" << r <<")("<<t << ")]\n";
            total = total * 1000;
            total = floor(total);
            total = total / 1000;
            cout << A << " = P (1+" << total <<")\n";
            total = 1 + total;
            cout << A <<  " = P (" << total << ")\n";
            P = A / total;
            cout << fixed << setprecision(2);
             cout << P << " = P";
             return BMS();
            break;
            default:
            cout << "\n\n\n*****************************************************************\n\n";
            cout << "            ***😡PLEASE ENTER THE AVAILABLE FORMULA😠***";
            
            return BMS();
            break;
        }
    }   
    void compoundInt(){
        cout << "\n\n**COMPOUND INTEREST**\n\n";
        cout << "available formula: \n";
        cout << "1.) FV = P (1+r/m)^tm\n";
        cout << "2.) I = FV - P\n";
        cout << "3.) r = m (n^√FV/P-1)\n";
        cout << "4.) P = FV / ( 1+ r/m)^tm\n";
        cout << "5.) Formula not found\n";
        cout << "your choice: ";
        cin >> choice;
        cout << "\n\nGIVEN: \n";
        switch (choice){
            case 1:
            cout << "\nenter the value of P: ";
            cin >> P;
            cout << "\nenter the value of m: ";
            cin >> m;
            cout << "\nenter the value of r: ";
            cin >> r;
            cout << "\nenter the value of year and month [ t ]: \n";
            cout << "\nyear/s: ";
            cin >> tyear;
            cout << "\ntmonth/s: ";
            cin >> tmonth;
            tmonth = tmonth / 12;
            t = tyear + tmonth;
            r = r / 100;
            cout << "\n\n [ FORMULA ]";
            cout << "\nFV = P (1+r/m)^tm\n";
            cout << "FV = " << P << "(1+ " <<r << "/" << m << ")^(" << t <<")(" << m << ") \n";
            
     rm = r/m;
            tm = t * m;
            cout << "FV = " << P << "(1+ " << rm << ")^" << tm;
            rm = rm + 1;
            cout << "\nFV = " << P << "(" << rm<<")^" << tm;
            total =  pow(rm, tm);
            total = total * 10000;
            total = floor(total);
            total = total / 10000;
            cout << "\nFV = " << P << "(" << total << ")\n";
            FV = P * total;  
            cout << "FV = " << FV; 
           return BMS();
            break;
            
            case 2:
            cout << "\nenter the value of P: ";
            cin >> P;
            cout << "\nenter the value of m: ";
            cin >> m;
            cout << "\nenter the value of r: ";
            cin >> r;
            cout << "\nenter the value of year and month [ t ]: \n";
            cout << "\nyear/s: ";
            cin >> tyear;
            cout << "\ntmonth/s: ";
            cin >> tmonth;
            
            tmonth = tmonth / 12;
            t = tyear + tmonth;
            
            r = r / 100;
            cout << "\n\n [ FORMULA ]";
            cout << "\nFV = P (1+r/m)^tm\n";
            cout << "FV = " << P << "(1+ " <<r << "/" << m << ")^(" << t <<")(" << m << ") \n";
            
     rm = r/m;
            tm = t * m;
            cout << "FV = " << P << "(1+ " << rm << ")^" << tm;
            rm = rm + 1;
            cout << "\nFV = " << P << "(" << rm<<")^" << tm;
            total =  pow(rm, tm);
            total = total * 10000;
            total = floor(total);
            total = total / 10000;
            cout << "\nFV = " << P << "(" << total << ")\n";
            FV = P * total;  
            cout << "FV = " << FV; 
            cout << "\nI = FV - P ";
            cout << "\nI = " << FV << "-"<<P; 
            cout << "\nI = " << FV - P;
           return BMS();
            break;
            case 3:
            
             cout << "\nenter the value of P: ";
            cin >> P;
            cout << "\nenter the value of m: ";
            cin >> m;
            cout << "\nenter the value of year and month [ t ]: \n";
            cout << "\nyear/s: ";
            cin >> tyear;
            cout << "\ntmonth/s: ";
            cin >> tmonth;
            cout << "\nenter the Future Value ( FV ): ";
            cin >> FV;
            tmonth = tmonth / 12;
            t = tyear + tmonth;
            cout << "\n\nn = 1 / t x m\n";
            cout << "n = 1 / " << t << " x " << m <<"\n";
            
            
             cout << "\n\n [ FORMULA ]";
             cout << "\nr = m (n^√FV/P-1)\n\n";
             
             //LOGIC
             
            cout << "r = " << m << " (" << t << " x " << m << "^" << "√" << FV << " / "<< P << "-1)\n";
            
            cout << "r = " << m << " ("<< t << " x " << m << "^" << "√" << FV / P << "-1)\n";
            tm = t * m;
            FV = FV / P;
           cout << "r = " << m << " ("<< tm << "^" << "√" << FV << "-1)\n";         
           tm = 1 / tm;          
           FV = pow(FV, tm);
           FV = FV * 10000;
           FV = floor(FV);
           FV = FV / 10000;
           cout << "r = " << m << " (" << FV << "-1)\n"; 
           FV = FV - 1;
           cout << "r = " << m << " ("<< FV << ")\n";
           
           r = m * FV;
           
           cout << "r = " << r;
           r = r * 100;
           cout << "\n\n r = " << r << "%\n";
           return BMS();
            break;
            case 4:
            cout << "\nenter the Future Value ( FV ): ";
            cin >> FV;
            cout << "\nenter the value of m: ";
            cin >> m;
            cout << "\nenter the value of r: ";
            cin >> r;
            cout << "\nenter the value of year and month [ t ]: \n";
            cout << "\nyear/s: ";
            cin >> tyear;
            cout << "\ntmonth/s: ";
            cin >> tmonth;
            tmonth = tmonth / 12;
            t = tyear + tmonth;
            r = r / 100;
            cout << "\n\n [ FORMULA ]";
            cout << "\nP = FV / (1+r/m)^tm\n";
            cout << "P = " << FV << "(1+ " <<r << "/" << m << ")^(" << t <<")(" << m << ") \n";
            
     rm = r/m;
            tm = t * m;
            cout << "P = " << FV << "(1+ " << rm << ")^" << tm;
            rm = rm + 1;
            cout << "\nP = " << FV << "(" << rm<<")^" << tm;
            total =  pow(rm, tm);
            total = total * 10000;
            total = floor(total);
            total = total / 10000;
            cout << "\nP = " << FV << " / (" << total << ")\n";
            P = FV / total;  
            cout << "P = " << P; 
            return BMS();
            break;
         
            default:
        cout << "\n\n\n*****************************************************************\n\n";
            cout << "            ***😡PLEASE ENTER THE AVAILABLE FORMULA😠***";
            
            cout << "\n\n\n*****************************************************************\n\n";          
            return BMS();
        }  
    }
};
int main (){ 
    BusinessMath Businessmath;
    Businessmath.BMS();
}