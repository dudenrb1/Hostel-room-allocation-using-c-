#include <iostream>
using namespace std;

class Room
{
private:
    struct node
    {
        int id, date;
        string name, roomtype;
        node* next;
    };

public:
    node* head = NULL;

    void insert();
    void menu();
    void update();
    void search();
    void del();
    void show();
};

void Room::menu()
{
    int choice;
    cout << "Welcome to the Room Booking System Application" << endl;

    do
    {
        cout << "\n-------------Room Booking SYSTEM---------";
        cout << "\n\nS.No.\tFunctions\t\tDescription" << endl;
        cout << "1\tAllocate Room\t\tInsert new room" << endl;
        cout << "2\tSearch Room\t\tSearch room with RoomID" << endl;
        cout << "3\tUpdate Room\t\tUpdate room record" << endl;
        cout << "4\tDelete Room\t\tDelete room with RoomID" << endl;
        cout << "5\tShow Room Records\tShow room records that we added" << endl;
        cout << "6\tExit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                update();
                break;
            case 4:
                del();
                break;
            case 5:
                show();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 6);
}

void Room::insert()
{
    cout << "\n____ Room Booking System____" << endl;
    node* new_node = new node;
    cout << "Enter Room ID: ";
    cin >> new_node->id;
    cout << "Enter Customer Name: ";
    cin >> new_node->name;
    cout << "Enter Allocated Date: ";
    cin >> new_node->date;
    cout << "Enter Room Type (single/double/triple): ";
    cin >> new_node->roomtype;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        node* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    cout << "\nNew Room Inserted Successfully!" << endl;
}

void Room::search()
{
    cout << "\n____Room Booking System___" << endl;
    int t_id;
    cout << "Enter Room ID to search: ";
    cin >> t_id;

    if (head == NULL)
    {
        cout << "\nLinked list is empty" << endl;
    }
    else
    {
        node* ptr = head;
        bool found = false;

        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                cout << "\nRoom ID: " << ptr->id << endl;
                cout << "Customer Name: " << ptr->name << endl;
                cout << "Room Allocated Date: " << ptr->date << endl;
                cout << "Room Type: " << ptr->roomtype << endl;
                found = true;
                break;
            }

            ptr = ptr->next;
        }

        if (!found)
        {
            cout << "Room not found!" << endl;
        }
    }
}

void Room::update()
{
    cout << "\n_____Room Booking System______" << endl;
    int t_id;
    cout << "Enter Room ID to update: ";
    cin >> t_id;

    if (head == NULL)
    {
        cout << "\nLinked list is empty" << endl;
    }
    else
    {
        node* ptr = head;
        bool found = false;

        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                cout << "\n\nRoom ID: " << ptr->id << endl;
                cout << "Enter New Room ID: ";
                cin >> ptr->id;
                cout << "Enter Customer Name: ";
                cin >> ptr->name;
                cout << "Enter Allocated Date: ";
                cin >> ptr->date;
                cout << "Enter Room Type (single/double/twin): ";
                cin >> ptr->roomtype;

                cout << "\n\t\tUpdate Record Successfully" << endl;
                found = true;
                break;
            }

            ptr = ptr->next;
        }

        if (!found)
        {
            cout << "Room not found!" << endl;
        }
    }
}

void Room::del()
{
    cout << "\n_____Room Booking System______" << endl;
    int t_id;
    cout << "Enter Room ID to delete: ";
    cin >> t_id;

    if (head == NULL)
    {
        cout << "\nLinked List is Empty" << endl;
    }
    else
    {
        if (t_id == head->id)
        {
            node* ptr = head;
            head = head->next;
            delete ptr;
            cout << "Deleted Room Record Successfully" << endl;
        }
        else
        {
            node* pre = head;
            node* ptr = head;

            while (ptr != NULL)
            {
                if (t_id == ptr->id)
                {
                    pre->next = ptr->next;
                    delete ptr;
                    cout << "Deleted Room Record Successfully" << endl;
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            }

            if (ptr == NULL)
            {
                cout << "Room not found!" << endl;
            }
        }
    }
}

void Room::show()
{
    if (head == NULL)
    {
        cout << "\nNo room records found!" << endl;
    }
    else
    {
        node* ptr = head;
        cout << "\n____Room Records____" << endl;

        while (ptr != NULL)
        {
            cout << "\nRoom ID: " << ptr->id << endl;
            cout << "Customer Name: " << ptr->name << endl;
            cout << "Room Allocated Date: " << ptr->date << endl;
            cout << "Room Type: " << ptr->roomtype << endl;

            ptr = ptr->next;
        }
    }
}

int main()
{
    Room r;
    r.menu();

    return 0;
}
