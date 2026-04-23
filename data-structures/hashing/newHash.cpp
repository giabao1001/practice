#include <iostream>
#include <vector>
using namespace std;

enum State{Emp, Rem, Occ};

struct Hashing{
    int key;
    State state;
    Hashing(){
        state = Emp;
    } 
};

struct openHashing{
    int tableSize;
    int probingType;
    vector<Hashing> table;
};

int getH1(int key, int m){
    return key % m;
}

int getH2(int key){
    return 1 + key % 5;
}

int getProbeIndex(openHashing &hash, int key, int step){
    int h1 = getH1(key,hash.tableSize);
    if (hash.probingType == 1){
        return (h1 + step) % hash.tableSize;
    }
    else if (hash.probingType == 2 ){
        return (h1 + step*step) % hash.tableSize;
    }
    else {
        int h2 = getH2(key);
        return (h1 + step*h2 ) % hash.tableSize;
    }
}

void Insert (openHashing &hash,int key){
    for (int step = 0; step < hash.tableSize; ++step){
        int index = getProbeIndex(hash,key,step);
        if (hash.table[index].state == Emp){
            hash.table[index].state = Occ;
            hash.table[index].key = key;
            return;
        }
    }
}

bool search (openHashing &hash, int key){
    for (int step = 0; step < hash.tableSize; ++ step){
        int index = getProbeIndex(hash,key,step);
        if (hash.table[index].state == Emp) return false;
        if (hash.table[index].state == Occ && hash.table[index].key == key) return true;
    }
    return false;
}

void remove (openHashing &hash, int key){
    for (int step = 0; step < hash.tableSize; ++step){
        int index = getProbeIndex(hash,key,step);
        if (hash.table[index].state == Emp) return;
        if (hash.table[index].state == Occ && hash.table[index].key == key ){
            hash.table[index].state = Rem;
            return;
        }
    }
}


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    return 0;
}