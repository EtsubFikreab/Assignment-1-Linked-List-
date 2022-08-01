#include "DLink.cpp"
using namespace std;
void welcomeMessage();
bool promptUserSortList();
void create(bool sort, int dataType);
void selectDataTypeMessage();
int selectDataType();

int main()
{
    // welcomeMessage();
    bool sort = promptUserSortList();
    int dataType = selectDataType();
    create(sort, dataType);
}

void welcomeMessage()
{
    cout << "Welcome" << endl
         << "\nThis is a mini-program that implements a doubly linked list" << endl
         << "Press any enter to continue...";
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
}
bool promptUserSortList()
{
    char yesOrNo;
    cout << "Should the Linked list be sorted" << endl
         << "Enter \'y/Y\' for yes or \'n/N\' for no: ";
    cin >> yesOrNo;
    while (!(yesOrNo == 'y' || yesOrNo == 'Y' || yesOrNo == 'n' || yesOrNo == 'N'))
    {
        cout << yesOrNo << "\nInvalid input please try again: ";
        cin >> yesOrNo;
    }
    if (yesOrNo == 'y' || yesOrNo == 'Y')
        return true;
    else
        return false;
}
void selectDataTypeMessage()
{
    cout << "Data Type" << endl
         << "-----------" << endl
         << "\n1.Integer"
         << "\n2.Character"
         << "\n3.Floating Point"
         << "\n4.Double Floating Point"
         << "\n5.Long Integer" << endl;

    cout << "\nEnter your choice: ";
}
int selectDataType()
{
    int choice = 0;
    while (choice < 1 || choice > 5)
    {
        selectDataTypeMessage();
        cin >> choice;
        if (!cin || choice < 1 || choice > 5)
        {
            cout << "\nInvalid input, press Enter to try again... ";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            choice = 0;
        }
        system("cls");
    }
    return choice;
}
void mainMenuMessage()
{
    cout << "Main Menu" << endl
         << "-----------" << endl
         << "\n1.Insert"
         << "\n2.Remove"
         << "\n3.Search"
         << "\n4.Display Forward"
         << "\n5.Display Backward"
         << "\n6.Exit" << endl;

    cout << "\nEnter your choice: ";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// mainMenu functions
// insert
template <class T>
T returnData()
{
    // gets data from the user and checks its validity
    T data;
    do
    {
        cout << "Enter the data you want to insert: ";
        cin >> data;
        if (!cin)
        {
            cout << "\nInvalid input, press Enter to try again... ";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
        }
    } while (!cin);
    return data;
}
template <class T>
T returnDataBeforeOrAfter()
{
    // gets data from the user and checks its validity
    T data;
    do
    {
        cout << "Enter the data you want to that comes before or after: ";
        cin >> data;
        if (!cin)
        {
            cout << "\nInvalid input, press Enter to try again... ";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
        }
    } while (!cin);
    return data;
}
int insertType()
{
    int choice;
    do
    {
        cout << "Insert Type" << endl
             << "-----------" << endl
             << "\n1.Insert"
             << "\n2.Insert First"
             << "\n3.Insert Last"
             << "\n4.Insert After a particular data"
             << "\n5.Insert Before a particular data" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;
        if (!cin || choice < 1 || choice > 5)
        {
            cout << "\nInvalid input, press Enter to try again... ";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            choice = 0;
        }
        system("cls");
    } while (choice < 1 || choice > 5);
    return choice;
}
template <class T>
void insertData(DList<T> *List, bool sort)
{
    if (sort)
    {
        List->insert(returnData<T>());
        return;
    }
    int iType = insertType();
    T data = returnData<T>();
    if (iType == 1)
        List->insert(data);
    else if (iType == 2)
        List->insertFirst(data);
    else if (iType == 3)
        List->insertBack(data);
    else if (iType == 4)
        List->insertAfter(returnDataBeforeOrAfter<T>(), data);
    else if (iType == 5)
        List->insertBefore(returnDataBeforeOrAfter<T>(), data);
}

// delete
int removeMessage()
{
    int choice;
    do
    {
        cout << "Remove Type" << endl
             << "-----------" << endl
             << "\n1.Remove specific data"
             << "\n2.Remove First"
             << "\n3.Remove Last"
             << "\n4.Remove by range" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;
        if (!cin || choice < 1 || choice > 5)
        {
            cout << "\nInvalid input, press Enter to try again... ";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            choice = 0;
        }
        system("cls");
    } while (choice < 1 || choice > 5);
    return choice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void MainMenu(DList<T> *List, bool sort)
{
    int choice = 0;
    while (choice != 6)
    {
        mainMenuMessage();
        cin >> choice;
        if (!cin || choice < 1 || choice > 6)
        {
            cout << "\nInvalid input,";
            cin.clear();
            choice = 0;
        }
        else if (choice == 1)
        {
            insertData(List, sort);
        }
        else if (choice == 2)
        {
        }
        else if (choice == 3)
        {
            
        }
        else if (choice == 4)
        {
            List->DisplayForward(&DefaultDisplayer);
        }
        else if (choice == 5)
        {
            List->DisplayBackward(&DefaultDisplayer);
        }
        if (choice != 1)
        {
            cout << "\npress Enter to continue... ";
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        cin.get();
        system("cls");
    }
}

void create(bool sort, int dataType)
{
    if (dataType == 1)
    {
        DList<int> *list = new DList<int>(sort);
        if (list != NULL)
            MainMenu(list, sort);
    }
    else if (dataType == 2)
    {
        DList<char> *list = new DList<char>(sort);
        if (list != NULL)
            MainMenu(list, sort);
    }
    else if (dataType == 3)
    {
        DList<float> *list = new DList<float>(sort);
        if (list != NULL)
            MainMenu(list, sort);
    }
    else if (dataType == 4)
    {
        DList<double> *list = new DList<double>(sort);
        if (list != NULL)
            MainMenu(list, sort);
    }
    else
    {
        DList<long> *list = new DList<long>(sort);
        if (list != NULL)
            MainMenu(list, sort);
    }
}