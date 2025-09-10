# DebugShape

minecraft bedrock debug shape packet wrapper

## Usage

- xmake.lua

```lua
add_repositories("engsr6982-repo https://github.com/engsr6982/xmake-repo.git")

add_requires("debug_shape 0.1.0")
```

```cpp
#include "debug_shape/DebugShape.h"

void enable() {
    auto shape = std::make_unique<debug_shape::DebugShape>();
    shape->draw();
    shape->remove();
}
```

## LICENSE

LGPL v3 or later
