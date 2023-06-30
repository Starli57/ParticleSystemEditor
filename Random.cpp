#include "Random.h"

Random::Random()
{

}

Random::Random(uint32_t defaultSeed) 
{
    seed = defaultSeed;
}


uint32_t Random::Get()
{
    return WangHash();
}

float Random::Get01() 
{
    constexpr uint32_t maxValue = std::numeric_limits<uint32_t>::max();
    return static_cast<float>(Get()) / static_cast<float>(maxValue);
}

float Random::Get(float min, float max)
{
	return min + (max - min) * Get01();
}

uint32_t Random::WangHash()
{
    seed = (seed ^ 61) ^ (seed >> 16);
    seed *= 9;
    seed = seed ^ (seed >> 4);
    seed *= 0x27d4eb2d;
    seed = seed ^ (seed >> 15);
    return seed;
}