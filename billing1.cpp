#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t     Supermarket Main Menu       \n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t|     1)Administrator    |\n";
    cout << "\t\t\t\t|                        |\n";
    cout << "\t\t\t\t|     2)Buyer            |\n";
    cout << "\t\t\t\t|                        |\n";
    cout << "\t\t\t\t|     3)Exit             |\n";
    cout << "\t\t\t\t|                        |\n";
    cout << "\n\t\t\t Please select!";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login  \n";
        cout << "\t\t\t Enter Email:   \n";
        cin >> email;
        cout << "\t\t\t Enter Password:\n";
        cin >> password;

        if (email == "12345@gmail.com" && password == "12345")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email/password";
        }
        break;
    case 2:
        buyer();
    case 3:
        exit(0);

    default:
        cout << "Plase select from the given options";
    }
    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator Menu";
    cout << "\n\t\t\t____1)Add the product_______|\n";
    cout << "\n\t\t\t                            |\n";
    cout << "\n\t\t\t____2)Modify the product____|\n";
    cout << "\n\t\t\t                            |\n";
    cout << "\n\t\t\t____3)Delete the product____|\n";
    cout << "\n\t\t\t                            |\n";
    cout << "\n\t\t\t____4)Back to main menu_____|\n";

    cout << "\n\n\t Please enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid Choice!";
    }
    goto m;
}

void shopping ::buyer()
{
    m:
    int choice;
    cout << "\t\t\t Buyer \n";
    cout << "______________________\n";
    cout << "                       \n";
    cout << "\t\t\t   1)Buy Product   \n";
    cout << "                   \n";
    cout << "\t\t\t   2)Go Back   \n";
    cout << "\t\t\t Enter your choice: ";

    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;  
    case 2:
        menu();
        
    default:
        cout << "Invalid Choice";
    }
    goto m;
}

void shopping ::add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product: ";
    cin >> pcode;
    cout << "\n\n\t Name of the product: ";
    cin >> pname;
    cout << "\n\n\t Price of the product: ";
    cin >> price;
    cout << "\n\n\t Discount on product: ";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }

    cout << "\n\n\t\t Record inserted !";
}

void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n File doesn't exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new code : ";
                cin >> c;
                cout << "\n\t\t Name of the product: ";
                cin >> n;
                cout << "\n\t\t Price : ";
                cin >> p;
                cout << "\n\t\t Discount : ";
                cin >> d;
                data1 << " " << c << " " << n << "" << p << "" << d << "\n";
                cout << "\n\n\t\t Record edited";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found sorry!";
        }
    }
}
void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code: ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << " File doesn't exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted succesfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found! ";
        }
    }
}

void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping ::receipt()
{

    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout << "\n\n\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database";
    }

    else
    {
        data.close();
        list();
        cout << "\n__________________________________\n";
        cout << "\n|                                 \n";
        cout << "\n|       Please place the order    \n";
        cout << "\n|                                 \n";
        cout << "\n__________________________________\n";

        do
        {
            m:
            cout << "\n\n Enter product code : ";
            cin >> arrc[c];
            cout << "\n\n Enter product quantity";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code. Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Dou you want to buy another product? If yes then press y else no";
            cin >> choice;

        } while (choice == 'y');
        cout << "\n\n\t\t\t_______________RECEIPTt_______________";
        cout << "\nProduct No\t Product Name\t Product Quantity\tPrice\tAmount\t\tAmount with discount";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }

        data.close();
    }

    cout << "\n\n______________________________________";
    cout << "\n Total Amount: " << total;
}

int main()
{
    shopping s;
    s.menu();
}