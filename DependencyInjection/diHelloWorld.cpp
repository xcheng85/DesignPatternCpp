#include "di.hpp"
#include <cassert>
#include <iostream>

namespace di = boost::di;
struct iworld {
  virtual ~iworld() noexcept = default;
};

struct world : iworld {
  world() { std::cout << " world!" << std::endl; }
};

struct hello {
  explicit hello(int i) {
    assert(42 == i);
    std::cout << "hello";
  }
};

template <class T = class Greater>
struct example {
  T h;
  iworld& w;
};

int main() {
  const auto injector = di::make_injector(
     di::bind<iworld>().to<world>()    // bind interface to implementation
   , di::bind<>().to(42)               // bind int to value 42
   , di::bind<class Greater>().to<hello>()   // bind template to type
  );

  /*<<create `example`>>*/
  injector.create<example>(); // or di::create<example>(injector)
}