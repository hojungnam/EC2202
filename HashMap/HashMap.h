// HashMap.h
#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class KeyException{
};

template <typename K, typename V, typename H>
class HashMap{
public:
    class Entry{
    private:
        K _key;
        V _value;
    public:
        Entry(const K& k, const V& v) : _key(k), _value(v) {}
        K key() const {return _key;}
        V value() const {return _value;}
        void setValue(const V& v1) {_value = v1;}
    };

    class Iterator;

public:
    HashMap(int capacity = 10);
    int size() const;
    bool empty() const;
    Iterator find(const K& k);
    Iterator put(const K& k, const V& v);
    void erase(const K& k) throw(KeyException);
    void erase(const Iterator& p);
    Iterator begin();
    Iterator end();

protected:
    typedef list<Entry> Bucket;
    typedef vector<Bucket> BktArray;
    typedef typename BktArray::iterator BItor;
    typedef typename Bucket::iterator EItor;
    Iterator finder(const K& k);
    Iterator inserter(const Iterator& p, const Entry& e);
    void eraser(const Iterator& p);
    static void nextEntry(Iterator& p)
    {++(p.ent);}
    static bool endOfBkt(const Iterator& p)
    {return p.ent == p.bkt->end();}

private:
    int n;
    H hash;
    BktArray B;

public:
    class Iterator{
    private:
        const BktArray* ba;
        BItor bkt;
        EItor ent;
    public:
        Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
            : ba(&a), bkt(b), ent(q) {}
        Entry& operator*() const;
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();
        friend class HashMap;
    };
};

template <typename K, typename V, typename H>	// constructor
HashMap<K,V,H>::HashMap(int capacity) : n(0), B(capacity) {}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry& HashMap<K,V,H>::Iterator::operator*() const
{
    return *ent;
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::Iterator::operator==(const Iterator& p) const
{
    if (ba != p.ba || bkt != p.bkt) return false;
    else if (bkt == ba->end()) return true;
    else return (ent == p.ent);
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::Iterator::operator!=(const Iterator& p) const
{
    return !(*this == p);
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator& HashMap<K,V,H>::Iterator::operator++()
{
    ++ent;
    if (endOfBkt(*this))
    {
        ++bkt;
        while (bkt != ba->end() && bkt->empty()) 
            ++bkt;
        if (bkt == ba->end()) return *this;
        ent = bkt->begin();
    }
    return *this;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::end()
{
    return Iterator(B, B.end());
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::begin()
{
    if (empty()) return end();
    BItor bkt = B.begin();
    while (bkt->empty()) 
        ++bkt;
    return Iterator(B, bkt, bkt->begin());
}

template <typename K, typename V, typename H>
int HashMap<K,V,H>::size() const
{
    return n;
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::empty() const
{
    return size() == 0;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::finder(const K& k)
{
    int i = hash(k) % B.size();
    BItor bkt = B.begin() + i;
    Iterator p(B, bkt, bkt->begin());
    while (!endOfBkt(p) && (*p).key() != k)
        nextEntry(p);
    return p;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::find(const K& k)
{
    Iterator p = finder(k);
    if (endOfBkt(p))
        return end();
    else
        return p;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::inserter(const Iterator& p,
const Entry& e)
{
    EItor ins = p.bkt->insert(p.ent, e);
    n++;
    return Iterator(B, p.bkt, ins);
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::put(const K& k, const V& v)
{
    Iterator p = finder(k);
    if (endOfBkt(p))
        return inserter(p, Entry(k, v));
    else
        p.ent->setValue(v);
        return p;
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::eraser(const Iterator& p)
{
    p.bkt->erase(p.ent);
    n--;
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const Iterator& p)
{
    eraser(p);
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const K& k) throw(KeyException)
{
    Iterator p = finder(k);
    if (endOfBkt(p))
        throw KeyException();
    eraser(p);
}

class HashFunc{
public:
    int operator()(int val)
    {
        return val;
    }
}; 
 
#endif
