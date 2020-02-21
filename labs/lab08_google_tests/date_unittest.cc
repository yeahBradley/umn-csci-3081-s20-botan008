#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};


// TEST_Fixture(ClassName, TestName) {}
TEST_F(DateTest, PrintDateTestsWithNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else
  //it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestsWithNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "12-31-1999\n";
  std::string expected_out_2 = "07-04-1776\n";
  std::string expected_out_3 = "10-31-2018\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else
  //it will segfault
  ind_day.PrintUsDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, GetDateTest) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  std::string output1 = y2k.GetDate();
  std::string output2 = ind_day.GetDate();
  std::string output3 = best_holiday.GetDate();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, GetUsDateTest) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";
  
  std::string output1 = y2k.GetUsDate();
  std::string output2 = ind_day.GetUsDate();
  std::string output3 = best_holiday.GetUsDate();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

// This method is failure. 
TEST_F(DateTest, DaysBetweenTests) {
  Date first_day(2018, 9, 4);          // First day of class
  Date last_day(2018, 12, 11);         // Last day of class
  int output1 = 98;

  Date pre_leap(2019, 1, 1);
  Date post_leap(2021, 1, 1);
  int output2 = 731;
  
  EXPECT_EQ(output1, first_day.DaysBetween(last_day));
  EXPECT_EQ(output1, last_day.DaysBetween(first_day));
  EXPECT_EQ(output2, pre_leap.DaysBetween(post_leap));
  EXPECT_EQ(output2, post_leap.DaysBetween(pre_leap));
}

// ERROR: This method uses "+" instead of "-"
TEST_F(DateTest, OperatorminusTests) {
  Date first_day(2018, 9, 4);          // First day of class
  Date last_day(2018, 12, 11);         // Last day of class
  Date output1 = last_day - 98;

  Date pre_leap(2019, 1, 1);
  Date post_leap(2021, 1, 1);
  Date output2 = post_leap - 731;

  EXPECT_EQ(first_day.GetDate(), output1.GetDate());
  EXPECT_EQ(pre_leap.GetDate(), output2.GetDate());
}

// This method is correct
TEST_F(DateTest, OperatorplusTests) {
  Date first_day(2018, 9, 4);          // First day of class
  Date last_day(2018, 12, 11);         // Last day of class
  Date output1 = first_day + 98;

  Date pre_leap(2019, 1, 1);
  Date post_leap(2021, 1, 1);
  Date output2 = pre_leap + 731;
  
  EXPECT_EQ(last_day.GetDate(), output1.GetDate());
  EXPECT_EQ(post_leap.GetDate(), output2.GetDate());
}
// ERROR: 
TEST_F(DateTest, ConstructorEpochTests) {
  Date epoch_zero(0); // 1970-1-1
  Date epoch_input(1970, 1, 1);

  EXPECT_EQ(epoch_zero.GetDate(), epoch_input.GetDate());
}

// ERROR: Default Constructor stores the wrong month
TEST_F(DateTest, ConstructerDefaultTests) {
  Date test1;
  Date test2;
  Date test3(2020, 2, 21);
  
  int yyyy_, mm_, dd_;
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  
  //tm year's value is years since 1900
  yyyy_ = now->tm_year + 1900;
  //tm month's value is zero-indexed
  mm_ = now->tm_mon + 1;
  //tm day's value is one-indexed
  dd_ = now->tm_mday;

  Date test4(yyyy_, mm_, dd_);
  EXPECT_EQ(test3.GetDate(), test1.GetDate());
  EXPECT_EQ(test1.GetDate(), test2.GetDate());
  EXPECT_EQ(test1.GetDate(), test4.GetDate());
}

// Param constructor has no range checking.
TEST_F(DateTest, ConstructorParamTests) {
  Date zero_day(0, 0, 0);
  Date one_day(1, 1, 1);
  Date neg_day(-1, -1, -1);

  EXPECT_NE(zero_day.GetDate(), neg_day.GetDate());
  EXPECT_NE(neg_day.GetDate(), one_day.GetDate()); 
}
/**
  *
  * Note, this is the only provided test case which actually uses our test
  * fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case
  * (file).
  *
  */
  
// TEST_F(DateTest, DaysBetweenTestsDefault) {
//   EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") 
//      << "First day of class not setup properly";
//   EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") 
//      << "Last day of class not setup properly";
//   EXPECT_EQ(first_day.DaysBetween(last_day), 98) 
//      << "Days between is not calculated properly";
// }



/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
