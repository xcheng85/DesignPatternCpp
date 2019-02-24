#include <iostream>
#include <string>
#include <map>

class Mapleton {
public:
    // Returns a reference to static instance of this class
    // based on provided string identifier
    static Mapleton& instance(const std::string& id) {
        static std::map<std::string, Mapleton> instances;
        auto it = instances.find(id);

        if (it != instances.end()) {
            return it->second;
        }

        Mapleton instance(id);
        auto insertIt = instances.emplace(id, std::move(instance));
        return insertIt.first->second;   
    }
    
    // The big five. We don't want singleton instances to be
    // copyable nor movable. They should always be accessed with
    // ::instance.
    ~Mapleton() = default;
    //Mapleton(Mapleton&) = delete;
    //Mapleton(Mapleton&&) = delete;
    //Mapleton(const Mapleton&) = delete;
    //Mapleton(const Mapleton&&) = delete;
    //Mapleton& operator=(const Mapleton&) = delete;
    //Mapleton& operator=(const Mapleton&&) = delete;
    
    void say_hello_id() {
        std::cout << "Hello " << id << std::endl;   
        std::cout << "Number is " << i << std::endl;
    }
    
    void increment() {
        i++;
    }
    
private:
    Mapleton(const std::string& id) : id{id}, i{0} {};
    std::string id;
    int i;
};

int main()
{
    auto& minst = Mapleton::instance("mapleton!");
    minst.say_hello_id();
    minst.increment();
    
    auto& mins2 = Mapleton::instance("mapleton!");
    mins2.say_hello_id();
    
    auto& mins3 = Mapleton::instance("PLOO");
    mins3.say_hello_id();
}