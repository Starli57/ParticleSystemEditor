
#include <iostream>

#include "Application.h"

int WinMain()
{
    std::unique_ptr<Application> app = std::make_unique<Application>();
    return 0;
}