
#include "react_value.h"

namespace Utilities
{
    template<typename T>
    T ReactValue<T>::GetValue() const
    {
        return value;
    }

    template<typename T>
    void ReactValue<T>::SetValue(T newValue) {
        value = newValue;
        if (onValueChanged) {
            onValueChanged();
        }
    }

    template<typename T>
    void ReactValue<T>::Subscribe(std::function<void()> callback) {
        onValueChanged = callback;
    }
}