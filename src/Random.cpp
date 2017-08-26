#include "Random.h"

namespace fisherman {
	SeedProvider::SeedProvider(unsigned int seed) : generator(seed) {}

	unsigned int SeedProvider::getSeed() const {
		return this->seed;
	}

	DefaultGenerator& SeedProvider::getGenerator() {
		return this->generator;
	}

	SeedProvider::~SeedProvider() {}
}