#include <iostream>
#include <string>
#include <ostream>

template <typename T>
class HeapArray
{
  private:
    size_t m_size;
    T *m_resource;

  public:
    // Resource is created explicilty at construction
    HeapArray(size_t size, T init)
        : m_size(size),
          m_resource(new (std::nothrow) T[size]) // don't throw bad_alloc exception, good for interview
    {
        std::cout << " [LOG] Intialize array with size = " << size
                  << " and init = " << init << std::endl;
        if (m_resource != nullptr) // fail to allocation 
            for (size_t i = 0; i < size; i++)
                m_resource[i] = init;
    }
    // Delegated constructor on the right size
    HeapArray(size_t size) : HeapArray(size, T{}) {}

    // Resource is released at destructor
    ~HeapArray()
    {
        std::cout << " [LOG] Destructor -> Delete array" << std::endl;
        // Always safe to delete
        delete[] m_resource;
        m_resource = nullptr;
    }

    // Forbid copy constructor
    HeapArray(const HeapArray &) = delete;
    // Forbid copy-assignment operator
    HeapArray &operator=(const HeapArray &) = delete;
    // Move constructor
    HeapArray(HeapArray &&rhs)
    {
        std::cout << " [LOG] Move constructor " << std::endl;
        std::swap(this->m_resource, rhs.m_resource);
    }
    // Move assignment operator
    HeapArray &operator=(HeapArray &&rhs)
    {
        std::cout << " [LOG] Move assignment operator " << std::endl;
        std::swap(this->m_resource, rhs.m_resource);
        return *this;
    }
    size_t size() const
    {
        return m_size;
    }
    T &operator[](size_t n)
    {
        return m_resource[n];
    }
    
    friend auto operator<<(std::ostream &os, const HeapArray<T> &rhs) -> std::ostream &
    {
        os << "[" << rhs.m_size << "]( ";
        for (size_t i = 0; i < rhs.m_size; i++)
            os << rhs.m_resource[i] << " ";
        os << ")";
        return os;
    }
};
