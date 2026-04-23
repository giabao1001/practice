#include <iostream>
#include <vector>

using namespace std;

// Sử dụng enum class để tránh xung đột tên và tường minh hơn
enum class State { Empty, Occupied, Removed };

struct Node {
    int key;
    State state = State::Empty;
};

class OpenHashTable {
private:
    int tableSize;
    int probingType; // 1: Linear, 2: Quadratic, 3: Double Hashing
    vector<Node> table;

    // Các hàm băm phụ (Helper functions)
    int h1(int key) const {
        return key % tableSize;
    }

    int h2(int key) const {
        return 1 + (key % 5);
    }

    int getProbeIndex(int key, int step) const {
        int baseHash = h1(key);
        switch (probingType) {
            case 1: // Linear Probing
                return (baseHash + step) % tableSize;
            case 2: // Quadratic Probing
                return (baseHash + step * step) % tableSize;
            case 3: // Double Hashing
                return (baseHash + step * h2(key)) % tableSize;
            default:
                return (baseHash + step) % tableSize;
        }
    }

public:
    OpenHashTable(int size, int type) : tableSize(size), probingType(type) {
        table.resize(tableSize);
    }

    void insert(int key) {
        for (int step = 0; step < tableSize; ++step) {
            int index = getProbeIndex(key, step);
            // Có thể chèn vào ô trống hoặc ô đã bị đánh dấu xóa (Removed)
            if (table[index].state != State::Occupied) {
                table[index].key = key;
                table[index].state = State::Occupied;
                return;
            }
        }
        cout << "Table Overflow: Could not insert " << key << endl;
    }

    bool search(int key) const {
        for (int step = 0; step < tableSize; ++step) {
            int index = getProbeIndex(key, step);
            if (table[index].state == State::Empty) return false;
            if (table[index].state == State::Occupied && table[index].key == key) {
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        for (int step = 0; step < tableSize; ++step) {
            int index = getProbeIndex(key, step);
            if (table[index].state == State::Empty) return;
            if (table[index].state == State::Occupied && table[index].key == key) {
                table[index].state = State::Removed;
                return;
            }
        }
    }

    void display() const {
        for (int i = 0; i < tableSize; ++i) {
            cout << "[" << i << "]: ";
            if (table[i].state == State::Occupied) cout << table[i].key;
            else if (table[i].state == State::Removed) cout << "X (Removed)";
            else cout << "- (Empty)";
            cout << endl;
        }
    }
};

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size = 13;
    int type = 1; // 1: Linear Probing

    OpenHashTable myHash(size, type);

    int keys[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    for (int k : keys) {
        myHash.insert(k);
    }

    cout << "Hash Table content:\n";
    myHash.display();

    int searchKey = 15;
    cout << "\nSearch " << searchKey << ": " << (myHash.search(searchKey) ? "Found" : "Not Found") << endl;

    myHash.remove(15);
    cout << "After removing 15, search 15: " << (myHash.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}