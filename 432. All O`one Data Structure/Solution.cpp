#include <list>

using namespace std;

class AllOne {
private:
    list<pair<int, unordered_set<string>>> keysOf;
    unordered_map<string, keysOf::iterator> valuesOf;
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key < Key > with value 1. Or increments an existing key by 1. */
    void inc(string &key) {
        if (list.empty()) {
            keysOf.insert(make_pair<int, unordered_set<string>>(1, unordered_set<string>()));
            (--keysOf.end())->insert(key);
            valuesOf[string] = keysOf.cbegin();
        } else {
            keysOf::iterator itr = valuesOf[key];
            if (++itr == keysOf.end())
                keysOf.insert(make_pair<int, unordered_set<string>>((--itr)->first + 1, unordered_set<string>()))
            (++itr)->second.insert(key);
            (--itr)->second.remove(key);
            if (itr->second.empty()) 
                keysOf.erase(itr);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string &key) {
        if (!valuesOf.count(key)) return;
        
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (keysOf.empty()) return "";
        else return *keysOf.rbegin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (keysOf.empty()) return "";
        else return *keysOf.begin();
    }
}

/**
    * Your AllOne object will be instantiated and called as such:
    * AllOne obj = new AllOne()
    * obj.inc(key)
    * obj.dec(key)
    * string param_3 = obj.getMaxKey()
    * string param_4 = obj.getMinKey()
    */
