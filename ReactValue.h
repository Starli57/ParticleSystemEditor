#pragma once

#include <iostream>
#include <functional>

namespace Utilities
{
    template<typename T>

    class ReactValue
    {
    private:
        T value;
        std::function<void()> onValueChanged;

    public:
        T GetValue() const;
        void SetValue(T newValue);
        void Subscribe(std::function<void()> callback);
    };
}
