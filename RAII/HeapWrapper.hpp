#include <iostream>
#include <cstdio>

template <class Resource>
class RAIIWrapper
{
  public:
    using Cleanup_fn = std::function<void(Resource *)>;

    // Constructor: Acquire resource
    // Parameter res      => Wrapped Resource
    // Parameter cleanup  => Clenup function which releases resources.
    RAIIWrapper(Resource *res, Cleanup_fn cleanup)
        : m_res(res), m_cleanup(cleanup) {}

    // Forbid copy-constructor
    RAIIWrapper(const RAIIWrapper &rhs) = delete;
    // Forbid copy-assignment operator
    RAIIWrapper &operator=(const RAIIWrapper &rhs) = delete;

    // Move constructor => Transfer resource ownership
    //  from teporary object rhs (R-value) to new object (this).
    RAIIWrapper(RAIIWrapper &&rhs)
    {
        this->m_res = rhs.m_res;
        rhs.m_res = nullptr;
    }
    // Move assignment operator - move resource ownership
    // from temporary object (rhs) in the right hand-size of (=)
    // to this object.
    RAIIWrapper &operator=(RAIIWrapper &&rhs)
    {
        std::swap(this->m_res, rhs.m_res);
        return *this;
    }

    void close()
    {
        if (m_res != nullptr)
            m_cleanup(m_res);
        m_res = nullptr;
        std::cerr << "LOG cleanup resource.";
    }
    // Destructor => Release resource
    ~RAIIWrapper()
    {
        this->close();
    }
    Resource *get() const { return m_res; }
    // Conversion operator to check whether wrapped pointer is null.
    operator bool() const
    {
        return m_res != nullptr;
    }

  private:
    Resource *m_res;
    Cleanup_fn m_cleanup;
};