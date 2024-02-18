#include <iostream>
#include <string>
using namespace std;
class Account
{
  private:
    string username[100], password[100];
    string confirmUser, confirmPass, choice;
    int size = 0;
    bool accountChecker = false;
    bool pressEnter = true;
  public:
    void registration()
    {
      if(pressEnter == true){
        cout << "       [ Welcome to my Authentication Algorithm ]";
        }  
        cout << "\n\n[ REGISTER ]\n";
        if (pressEnter == true)
        {
            cout << "\nPress [ ENTER ] to continue: ";
        }        
        clearInputBuffer();
        //i use this function "clearInputBuffer()" to clear the input buffer because getline cin won't work properly without this
        cout << "\nUsername: ";
        getline(cin, username[size += 1]);
        cout << "Password: ";
        cin >> password[size];
        if (size > 98)
        {
            cout << "\n\n You can't creat more account! \n\n";
            size -= 1;
            return registration();
        }
        login();
    }
    void login()
    {
        do
        {
            cout << "\n\n [ LOGIN ] \n\n";
            cout << "Username: ";
            clearInputBuffer();
            getline(cin, confirmUser);
            cout << "Password: ";
            cin >> confirmPass;
            for (int i = 1; i <= size; i++)
            {
                if (confirmUser == username[i] && confirmPass == password[i])
                {
                    accountChecker = true;
                }
            }
            if (accountChecker == true)
            {
                cout << "\nLogin successfully \n";
            }
            else
            {
                cout << "\nInvalid username or password. Please try again.\n";
            }
        } while (accountChecker == false);
        accountChecker = false;
        cout << "\n\nDo you want to create another account? \n";
        cout << "PRESS [ 1 ] if yes, PRESS [ ANYTHING ] if no: ";
        cin >> choice;

        if (choice == "1")
        {
            pressEnter = false;
            return registration();
        }
    }
    void clearInputBuffer()
{
    int c;                                                         
    while ((c = getchar()) != '\n' && c != false/* or EOF */);
}
};
int main()
{
    Account account;
    account.registration();
    return 0;
}