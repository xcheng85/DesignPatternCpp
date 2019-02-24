#include "di.hpp"
#include <cassert>

namespace di = boost::di;

struct iworld
{
    virtual ~iworld() noexcept = default;
    virtual void f() = 0;
};

struct world : iworld
{
    void f() override {}
};

struct hello
{
    explicit hello(iworld &) {}
};

int main()
{
    {
        const auto injector = di::make_injector(di::bind<iworld>().to<world>());
        static_assert(di::is_creatable<hello>(injector), "");
    }

    {
        const auto injector = di::make_injector();
        static_assert(!di::is_creatable<hello>(injector), "iworld is not abstract!");
    }
}