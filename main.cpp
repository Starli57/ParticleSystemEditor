
#include <iostream>

#include "../code/application/AppRuntime.h"

int WinMain()
{
    std::unique_ptr<AppRuntime> appRuntime = std::make_unique<AppRuntime>();

    return 0;
}