#pragma once

#include <vector>
#include <string>
#include <random>

namespace fisherman {
	typedef std::mt19937 DefaultGenerator;

	class SeedProvider {
	public:
		SeedProvider(unsigned int seed);

		unsigned int getSeed() const;
		DefaultGenerator& getGenerator();

		virtual ~SeedProvider();

	private:
		unsigned int seed;
		DefaultGenerator generator;
	};

	static float randomNormal(float mean, float stdDev, SeedProvider* seedProvider = nullptr) {
		std::normal_distribution<float> distribution(mean, stdDev);
		if (seedProvider == nullptr) {
			std::random_device generator;
			return distribution(generator);
		}
		return distribution(seedProvider->getGenerator());
	}

	static int randomInt(int from, int to, SeedProvider* seedProvider = nullptr) {
		if (to <= from) {
			return from;
		}
		std::uniform_int_distribution<> distribution(from, to);
		if (seedProvider == nullptr) {
			std::random_device generator;
			return distribution(generator);
		}
		return distribution(seedProvider->getGenerator());
	}

	template<typename RealType_> static RealType_ randomReal(RealType_ from, RealType_ to, SeedProvider* seedProvider = nullptr) {
		if ((to - from) < 1.0e-4f) {
			return from;
		}
		std::uniform_real_distribution<RealType_> distribution(from, to);
		if (seedProvider == nullptr) {
			std::random_device generator;
			return distribution(generator);
		}
		return distribution(seedProvider->getGenerator());
	}	

	template<typename Type_> static const Type_& randomSelect(const std::vector<Type_>& values, SeedProvider* seedProvider = nullptr) {
		if (values.empty()) {
			throw std::runtime_error("randomSelect received an empty container");
		}		
		return values[randomInt(0, values.size() - 1, seedProvider)];
	}

	static std::string randomAlphanumericString(int minChars, int maxChars, SeedProvider* seedProvider = nullptr) {
		std::string characters("1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
		std::random_device generator;

		std::string password = "";
		std::uniform_int_distribution<> distribution(0, characters.size() - 1);
		int nChars = randomInt(minChars, maxChars);
		for (int i = 0; i < nChars; ++i) {
			if (seedProvider == nullptr) {
				password += distribution(generator);
			} else {
				password += distribution(seedProvider->getGenerator());
			}
		}
		return password;
	}
}