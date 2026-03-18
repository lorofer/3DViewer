#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

#include "model.h"
#include "obj_parser.h"
#include "wireframe.h"

TEST(ModelSuite, ModelTest) {
	s21::Model model = {};

	model.SetWireframeFromFile("obj/cube.obj");

	std::vector<float> vbo = model.GetVertexBuffer();

	EXPECT_EQ(12, std::count(vbo.begin(), vbo.end(), -1.0f));
	EXPECT_EQ(12, std::count(vbo.begin(), vbo.end(), 1.0f));

	std::vector<int> ebo = model.GetEdgesBuffer();

	std::vector<int> e1 = {0, 6};
	std::vector<int> e2 = {6, 4};
	std::vector<int> e3 = {4, 0};
	std::vector<int> e4 = {0, 2};
	std::vector<int> e5 = {2, 6};
	std::vector<int> e6 = {0, 3};
	std::vector<int> e7 = {3, 2};
	std::vector<int> e8 = {0, 1};
	std::vector<int> e9 = {1, 3};
	std::vector<int> e10 = {2, 7};
	std::vector<int> e11 = {7, 6};
	std::vector<int> e12 = {3, 7};
	std::vector<int> e13 = {7, 4};
	std::vector<int> e14 = {7, 5};
	std::vector<int> e15 = {5, 4};
	std::vector<int> e16 = {5, 0};
	std::vector<int> e17 = {5, 1};
	std::vector<int> e18 = {7, 1};

	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e1.begin(), e1.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e2.begin(), e2.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e3.begin(), e3.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e4.begin(), e4.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e5.begin(), e5.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e6.begin(), e6.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e7.begin(), e7.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e8.begin(), e8.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e9.begin(), e9.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e10.begin(), e10.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e11.begin(), e11.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e12.begin(), e12.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e13.begin(), e13.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e14.begin(), e14.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e15.begin(), e15.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e16.begin(), e16.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e17.begin(), e17.end()) != ebo.end());
	EXPECT_TRUE(std::search(ebo.begin(), ebo.end(), e18.begin(), e18.end()) != ebo.end());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}