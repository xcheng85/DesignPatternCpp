#pragma once

#include <map>
#include <string>

/*
    Multiton pattern template. It's similar to the singleton pattern, but
    enables multiple instances through the use of keys.
    NOTE: Manual destruction must be done before program exit. Not thread-safe.
    
    class Foo : public Multiton<Foo> {};
    Foo &foo = Foo::getRef("foobar");
    foo.bar();
    Foo::destroyAll();
 */

template <typename T, typename Key = std::string>
class Multiton
{
public:
    static void destroyAll()
    {
        for (auto it = instances.begin(); it != instances.end(); ++it)
            delete (*it).second;
        instances.clear();
    }
    
    static void destroy(const Key &key)
    {
        auto it = instances.find(key);
        
        if (it != instances.end()) {
            delete (*it).second;
            instances.erase(it);
        }
    }

    static T* getPtr(const Key &key)
    {
        const auto it = instances.find(key);
        
        if (it != instances.end())
            return (T*)(it->second);
        
        T* instance = new T;
        instances[key] = instance;
        return instance;
    }
    
    static T& getRef(const Key &key)
    {
        return *getPtr(key);
    }
    
protected:
    Multiton();
    ~Multiton();
    
private:
    Multiton(const Multiton&);
    Multiton& operator=(const Multiton&);
    
    static std::map<Key, T*> instances;
};

template <typename T, typename Key>
std::map<Key, T*> Multiton<T, Key>::instances;
