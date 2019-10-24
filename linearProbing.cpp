//CMPE250 - Fall 2019
//PS5 - Hashing with linear probing

#include<iostream>

using namespace std;
class Hash
{
public:
    int *a,tableSize,currentTableSize;
    Hash(int n)
    {
        a=new int[tableSize=n];
        for(int i=0; i<tableSize; i++)
        {
            a[i] = -1;
        }
        currentTableSize = 0;
    }
    void insert(int);
    int remove(int);
    int findItem(int);
    void display();
};

void Hash::insert(int x)
{
    if(currentTableSize == tableSize)
    {
        cout << "\nHash table is full.";
    }
    else
    {
        int key = x%tableSize;
        int homeCell = key;
        if(a[key] == -1)
        {
            a[key] = x;
            currentTableSize++;
            cout << "\n" << x << " Element inserted at " << key;
        }
        else
        {
            while(1)
            {
                key++;

                if (key == tableSize)
                    key = 0;

                if(key == homeCell) //returned to home cell
                    return;
                else
                {
                    if(a[key] == -1)
                    {
                        a[key] = x;
                        currentTableSize++;
                        cout << "\n" << x << "  Element inserted at  " << key;
                        return;
                    }
                }

            }

        }
    }
}

int Hash::remove(int m)
{
    int key = m%tableSize;
    int homeCell = key;
    if(currentTableSize == 0)
    {
        return 0;
    }
    if(a[key] == m)
    {
        a[key] = -1;
        currentTableSize--;
        return key;
    }
    else
    {
        while(1)
        {
            key++;
            if (key == tableSize)
                key = 0;

            if(key == homeCell) //returned to home cell
                return 100;

            if(a[key] == m)
            {
                a[key] == -1;
                currentTableSize--;
                return key;
            }
        }

    }
}
int Hash::findItem(int m)
{
    int key = m%tableSize;
    int homeCell = key;
    if(currentTableSize == 0)
        return 0;
    else if(a[key] == m)
        return key;
    else
    {
        while(1)
        {
            key++;
            if (key == tableSize)
                key = 0;

            if(key == homeCell) //returned to home cell
                return 100;

            if(a[key] == m)
            {
                return key;
            }
        }

    }

}
void Hash::display()
{
    for(int i=0; i<tableSize; i++)
    {
        if(a[i] != -1)
        {
            cout << endl << i << "  " << a[i];
        }
    }
}
int main()
{
    int n,x,choice,returnVal;
    cout << "\n Enter size of the hash table: ";
    cin >> n;
    Hash linearProbing(n);
    while(1)
    {
        cout<<"\n1. Insert\n2. Remove\n3. Find\n4. Display\n5. Exit\n Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "\n Enter an element to insert: ";
                cin >> x;
                linearProbing.insert(x);
                break;
            case 2:
                cout <<"\n Enter an element to delete: ";
                cin >> x;
                returnVal = linearProbing.remove(x);
                if(returnVal == 100)
                {

                    cout << "\nElement is not in the list\n";
                }
                else if(returnVal == 0)
                {
                    cout <<"\n Hash table empty\n";
                }
                else
                {
                    cout << "\n Deleted element " << x << " at position " << returnVal << endl;
                }
                break;
            case 3:
                cout << "\n Enter an element to find: ";
                cin >> x;
                returnVal = linearProbing.findItem(x);
                if(returnVal == 100)
                {

                    cout << "\nElement is not in the list\n";
                }
                else if(returnVal == 0)
                {
                    cout << "\n Hash table empty\n";
                }
                else
                {
                    cout << "\nElement " << x <<  " founded at position " << returnVal << endl;
                }
                break;
            case 4:
                linearProbing.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "\n Wrong choice\n";

        }
    }

    return 0;

}