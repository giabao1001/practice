#include <iostream>
#include <vector> 
using namespace std;

enum State {Emp, Occ, Rem};

struct Hashing{
    int key;
    State state;
    Hashing(){
        state = Emp;
    }
};

struct OpenHash{
    int tableSize;
    int probingType;
    vector<Hashing> table;
};

int getAd(int key, int m){
    return key % m;
}

int jumpSize(int key){
    return 1 + key % 5;
}

int getProbeIndex(OpenHash &hash, int key, int step){
    int h1 = getAd(key, hash.tableSize);
    if (hash.probingType == 1 ){
        return (h1 + step) % hash.tableSize;
    }
    else if (hash.probingType == 2 ){
        return (h1 + step*step ) % hash.tableSize;
    }
    else {
        int h2 = jumpSize(key);
        return ( h1 + step*h2 ) % hash.tableSize;
    }
}

void insert(OpenHash &hash,int key){
    for (int step = 0; step < hash.tableSize; ++ step ){
        int index = getProbeIndex(hash,key,step);
        if (hash.table[index].state != Occ){
            hash.table[index].key = key;
            hash.table[index].state = Occ;
            return;
        }
    }
}

bool search (OpenHash &hash,int key){
    for (int step = 0; step < hash.tableSize; ++step){
        int index = getProbeIndex(hash,key,step);
        if (hash.table[index].state == Emp ) return false;
        if (hash.table[index].state == Occ && hash.table[index].key == key) return true;
    }
    return false;
}

void remove(OpenHash &hash, int key){
    for (int step = 0; step < hash.tableSize; ++step){
        int index = getProbeIndex(hash,key,step);
        if (hash.table[index].state == Emp) return;
        if (hash.table[index].state == Occ && hash.table[index].key == key ) {
            hash.table[index].state = Rem;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    OpenHash myHash;
    int n ;
    cin >> n;
    myHash.tableSize = 13;
    int type;
    cout << "probing type: ";
    cin >> type;
    myHash.table.resize(myHash.tableSize);
    int keys[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    return 0;
}