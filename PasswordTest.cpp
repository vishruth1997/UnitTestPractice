/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, double_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}
TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, upper_lower_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Password");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, upper_lower_password1)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("password");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, emptyPassword)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, aplha_num)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Tn71SDas");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, Last_capital)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("passworD");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, original_password)
{
	Password my_password;
	bool actual = my_password.authenticate("SomePassword");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, set_password)
{
	Password my_password;
	my_password.set("NewPassword123");
	bool actual = my_password.authenticate("NewPassword123");
	ASSERT_EQ(true, actual);
}

