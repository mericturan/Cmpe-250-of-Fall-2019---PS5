//CMPE250 - Fall 2019
//PS5 - Hashing with separate chaining

#include<iostream>
#include <list>

using namespace std;


class Hashing
{
    int hash_bucket;    // No. of buckets/cells
    list<int> *hashtable; // Pointer to an array containing buckets/cells

public:

    Hashing(int V);  // Constructor

    // inserts a key into hash table
    void insert_key(int val);

    // deletes a key from hash table
    void delete_key(int key);

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % hash_bucket);
    }

    void displayHash();
};

Hashing::Hashing(int b) //hash table creation
{
    this->hash_bucket = b;
    hashtable = new list<int>[hash_bucket];
}

//insert to hash table
void Hashing::insert_key(int key)
{
    int index = hashFunction(key); // get the hash index for key
    hashtable[index].push_back(key);
}

void Hashing::delete_key(int key)
{
    int index = hashFunction(key); // get the hash index for key

    // find the key in the linked list
    list <int> :: iterator i;

    for (i = hashtable[index].begin(); i != hashtable[index].end(); i++) {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it
    if (i != hashtable[index].end())
        hashtable[index].erase(i);
}

// display the hash table
void Hashing::displayHash() {

    for (int i = 0; i < hash_bucket; i++) {

        cout << i;

        for (auto x : hashtable[i])

            cout << " -> " << x;

        cout << endl;

    }

}

// main program

int main() {

    // array that contains keys to be mapped

    int hash_array[] = {11,12,21,14,15};

    int n = sizeof(hash_array)/sizeof(hash_array[0]);

    Hashing h(7);         // Number of buckets/cells = 7

    //insert the keys into the hash table
    for (int i = 0; i < n; i++)
        h.insert_key(hash_array[i]);

    // display the Hash table
    cout << "Hash table created:" << endl;
    h.displayHash();


    int deletion = 21;
    // delete some key from hash table
    h.delete_key(deletion);

    // display the Hash table
    cout << "Hash table after deletion of key "<< deletion << ":" << endl;
    h.displayHash();

    return 0;
}