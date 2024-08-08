#include <iostream>
#include <cstring>

using namespace std;

class Node
{
public:
    int num;
    int fill;
    char name[3][10];
    Node *next;
    Node *prev;

    Node(int num = 0) : num(num), fill(0), next(nullptr), prev(nullptr) {}
};

class Hostel
{
    Node *header[3];

public:
    Hostel()
    {
        for (int i = 0; i < 3; ++i)
            header[i] = nullptr;
    }

    ~Hostel()
    {
        for (int i = 0; i < 3; ++i)
        {
            Node *current = header[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    void create()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                Node *nn = new Node((j % 3) + 1);
                if (header[i] == nullptr)
                {
                    header[i] = nn;
                }
                else
                {
                    Node *cn = header[i];
                    while (cn->next != nullptr)
                        cn = cn->next;
                    cn->next = nn;
                    nn->prev = cn;
                }
            }
        }
    }

    void display()
    {
        for (int i = 0; i < 48; ++i)
            cout << "--";
        cout << "\n ";

        for (int i = 1; i <= 3; ++i)
            cout << "| Floor number : " << i << " \t\t";
        cout << "|\n";

        for (int i = 0; i < 48; ++i)
            cout << "--";

        for (int floor = 0; floor < 3; ++floor)
        {
            Node *cn = header[floor];
            cout << "\n ";
            for (int room = 1; cn != nullptr; ++room)
            {
                cout << "| room no : " << room;
                if (cn->fill < cn->num)
                    cout << " -> Vacant cots: " << (cn->num - cn->fill);
                else
                    cout << " -> Present";
                cout << "\t ";
                cn = cn->next;
            }
            cout << "|\n";
            for (int i = 0; i < 48; ++i)
                cout << "--";
        }
        cout << "\n";
    }

    void book(int people)
    {
        int floor, room;
        cout << "\nEnter the floor number (1-3): ";
        cin >> floor;
        if (floor < 1 || floor > 3)
        {
            cout << "Invalid floor number\n";
            return;
        }

        cout << "\nEnter the room number (1-9): ";
        cin >> room;
        if (room < 1 || room > 9)
        {
            cout << "Invalid room number\n";
            return;
        }

        Node *cn = header[floor - 1];
        for (int i = 1; i < room; ++i)
        {
            cn = cn->next;
        }

        if (cn->num >= people)
        {
            cout << "Room is vacant, you can apply for the room\n";
            for (int i = 0; i < people; ++i)
            {
                cout << "Enter name " << (cn->fill + 1) << ": ";
                cin >> cn->name[cn->fill];
                cn->fill++;
            }
            cn->num -= people;
        }
        else
        {
            cout << "Room is not vacant... SORRY!!!\n";
        }
    }

    void cancel(int floor)
    {
        char namecheck[10];
        int room;
        cout << "Enter the room number (1-9): ";
        cin >> room;
        if (room < 1 || room > 9)
        {
            cout << "Invalid room number\n";
            return;
        }

        cout << "Enter the name to be deleted: ";
        cin >> namecheck;

        Node *cn = header[floor - 1];
        for (int i = 1; i < room; ++i)
        {
            cn = cn->next;
        }

        for (int i = 0; i < cn->fill; ++i)
        {
            if (strcmp(namecheck, cn->name[i]) == 0)
            {
                cout << "Record deleted: " << cn->name[i] << "\n";
                for (int j = i; j < cn->fill - 1; ++j)
                {
                    strcpy(cn->name[j], cn->name[j + 1]);
                }
                cn->fill--;
                cn->num++;
                return;
            }
        }
        cout << "Record not present\n";
    }

    void upgrade(int floor)
    {
        char namecheck[10];
        int room;
        cout << "Enter the room number (1-9): ";
        cin >> room;
        if (room < 1 || room > 9)
        {
            cout << "Invalid room number\n";
            return;
        }

        cout << "Enter the name to be updated: ";
        cin >> namecheck;

        Node *cn = header[floor - 1];
        for (int i = 1; i < room; ++i)
        {
            cn = cn->next;
        }

        for (int i = 0; i < cn->fill; ++i)
        {
            if (strcmp(namecheck, cn->name[i]) == 0)
            {
                cout << "Enter updated name: ";
                cin >> cn->name[i];
                cout << "Record updated. Previous name: " << namecheck << ", Updated name: " << cn->name[i] << "\n";
                return;
            }
        }
        cout << "Record not found\n";
    }
};

int main()
{
    Hostel obj;
    int key;
    char ch;
    int floorcheck;
    obj.create();
    do
    {
        cout << "\n1. Book a room for 1 person\n2. Book a room for 2 people\n3. Book a room for 3 people\n4. Display the current status of rooms\n5. Cancel a cot\n6. Upgrade\n";
        cout << "Enter your choice: ";
        cin >> key;
        switch (key)
        {
        case 1:
            obj.book(1);
            break;
        case 2:
            obj.book(2);
            break;
        case 3:
            obj.book(3);
            break;
        case 4:
            obj.display();
            break;
        case 5:
            cout << "Enter floor number (1-3): ";
            cin >> floorcheck;
            if (floorcheck >= 1 && floorcheck <= 3)
                obj.cancel(floorcheck);
            else
                cout << "Invalid floor number\n";
            break;
        case 6:
            cout << "Enter floor number (1-3): ";
            cin >> floorcheck;
            if (floorcheck >= 1 && floorcheck <= 3)
                obj.upgrade(floorcheck);
            else
                cout << "Invalid floor number\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
        cout << "Do you want to continue (Y/N)? ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
