#include <gtest_wrapper.h>
#include <Random.h>

TEST(UtilsTests, RandomIntTest) {
	auto value = fisherman::randomInt(0, 10);
	EXPECT_TRUE(value >= 0 && value <= 10);
}

TEST(UtilsTests, RandomRealTest) {
	auto value = fisherman::randomReal(0.0f, 10.0f);
	EXPECT_TRUE(value > 0.0f && value < 10.0f);
}

TEST(UtilsTests, RandomAlphanumericStringTest) {
	std::string randomPassword = fisherman::randomAlphanumericString(6, 15);
	EXPECT_TRUE(randomPassword.size() >= 6 && randomPassword.size() <= 15);
}

TEST(UtilsTests, RandomSelectTest) {
	std::vector<int> options;
	options.push_back(10);
	options.push_back(20);
	options.push_back(30);
	options.push_back(40);

	auto value = fisherman::randomSelect(options);
	EXPECT_TRUE(value == 10 || value == 20 || value == 30 || value == 40);
}

TEST(UtilsTests, SeedProviderTest) {
	fisherman::SeedProvider seedProvider(2);
	EXPECT_EQ(fisherman::randomInt(0, 100, &seedProvider), 14);
	EXPECT_EQ(fisherman::randomInt(0, 100, &seedProvider), 78);
	EXPECT_EQ(fisherman::randomInt(0, 100, &seedProvider), 3);
	EXPECT_EQ(fisherman::randomInt(0, 100, &seedProvider), 1);
}
