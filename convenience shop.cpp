#include<string>
#include<iostream>
#include<ctime>
using namespace std;
class Store{
    private:
    string store;
    char choice;
     int cash = 500, buy, ask;
     bool noBack = false;
    public:
    Store(){
        srand(time(NULL));
    cash = (rand() & cash + 500);
    }
    void choices(){
        if( noBack == false ){
        cout << "enter your last name: ";
        cin >> store;
        noBack = true;
        }
        else if( noBack == true ){
            cout << "\ndo you want to continue?\n";
            cout << "\npress [ 1 ] to continue, [ 0 ] to exit: ";
            cin >> ask;
            if(ask == 1){
                
            }
            else if(ask == 0){
                return;
            }
        }
    cout << "\n\n\n\n       *****welcome to " << store << "'s Convenience Store*****\n\n";
    cout << "[you have the amount of: " << cash << " pesos]\n";
    cout << "\n\nChoose an item you want to buy: ";
    cout << "\n\na.) Charcoal (35 pesos/kilo)\n";
    cout << "b.) Mango (200 pesos/kilo)\n";
    cout << "c.) Sprite (40 pesos)\n";
    cout << "your choices: ";
    cin >> choice;
    switch(choice){
        case 'a':
        charcoal();
        break;
        case 'b':
        mango();
        break;
        case 'c':
        sprite();
        break;
        default:
        cout << "\n\n[ invalid choice ]\n\n";
        return choices();
        break;
    }
    
    }
    void charcoal(){
        cout << "\n\nhow many Charcoal (kilo): ";
        cin >> buy;
        buy = buy * 35;
        if(cash >= buy ){
            cash = cash - buy;
            cout << "\nthe total charge is: " << buy << " pesos per kilo\n";
            return choices();
        }
        else{
            cout << "\nnot enough money\n";
            return choices();
        }
        
    }
    void mango(){
        cout << "\n\nhow many Mango (kilo): ";
        cin >> buy;
        buy = buy * 200;
        if(cash >= buy ){
            cash = cash - buy;
            cout << "\nthe total charge is: " << buy << " pesos per kilo\n";
            return choices();
        }
        else{
            cout << "\nnot enough money\n";
            return choices();
        }
        
    }
    void sprite(){
        cout << "how many sprite do you want: ";
        cin >> buy;
        buy = buy * 40;
        if( cash >= buy ){
            cash = cash - buy;
            cout << "the total charge is: " << buy << " pesos per piece/s\n";
            return choices();
        }
        else{
            cout << "\nnot enough money\n";
            return choices();
        }
    }   
};
int main (){    
    Store store;
    store.choices();
}