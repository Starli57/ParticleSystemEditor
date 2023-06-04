
#include "di.h"

namespace Utilities
{

	std::unordered_map<std::type_index, std::shared_ptr<void>> DI::dependencies;

}