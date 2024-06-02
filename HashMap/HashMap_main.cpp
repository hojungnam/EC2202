#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "HashMap.h"

using namespace std;


int main()
{
    HashMap<int, string, HashFunc> m;
    cout << m.size() << endl;
    if (m.empty())
        cout << "Map is empty!" << endl;
    m.put(0, "Neil");
    m.put(5, "Amy");
    m.put(6, "Kate");
    m.put(4, "Colin");
    m.put(14, "Bob");
    cout << "Hash Table's size is " << m.size() << endl;
    for (HashMap<int, string, HashFunc>::Iterator p = m.begin(); p != m.end(); ++p)
        cout << (*p).key() << " " << (*p).value() << endl;

    HashMap<int, string, HashFunc>::Iterator q = m.find(0);
    cout << (*q).key() << " " << (*q).value() << endl;
    HashMap<int, string, HashFunc>::Iterator r = m.find(13);
    if (r == m.end())
        cout << "find works correctly" << endl;
    m.erase(q);
    m.erase(4);
    cout << "Hash Table's size is " << m.size() << endl;
    
    return 0;
}
