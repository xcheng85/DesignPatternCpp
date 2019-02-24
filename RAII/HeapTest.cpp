#include <iostream>
#include <string>
#include <memory>     // Smart pointers 
#include <functional> // std::function 
#include "HeapWrapper.hpp"

void writeFile(const char *file)
{
    // The wrapper automatically release the wrapped resource when out of scope
    RAIIWrapper<FILE> fptr(::fopen(file, "w"), &fclose);
    if (!fptr)
    {
        ::fputs(" [ERROR] Failed to create file\n", stderr);
        return;
    }
    ::fputs("Testing line 1\n", fptr.get());
    ::fputs("Testing line 2\n", fptr.get());
    ::fputs("C++17 is AWESOME! AMAZING!\n", fptr.get());
}

// Type alias for smart pointer with custom deleter 
template<typename T>
using Resource = std::unique_ptr<T, std::function<void (T*)>>;

void writeFileSmart(const char* file)
{
     // The wrapper automatically release the resource when out of scope
     Resource<FILE> fptr(::fopen(file, "w"),
                         // Custom-deleter function 
                         [](FILE* hnd){
                           std::cerr << " [TRACE] File closed OK." << std::endl;
                           if(hnd != nullptr) ::fclose(hnd);
                         });
     if(!fptr){
        ::fputs(" [ERROR] Failed to create file\n", stderr);
        return;
     }
     ::fputs("Testing line 1\n", fptr.get());
     ::fputs("Testing line 2\n", fptr.get());
     ::fputs("C++17 is AWESOME! AMAZING!\n", fptr.get());
}

int main()
{
    writeFile("/tmp/raii-resource.txt");
    writeFile("/etc/raii-resource.txt");   
}
