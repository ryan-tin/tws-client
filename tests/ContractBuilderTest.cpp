#include <gtest/gtest.h>
#include "ContractRequestBuilder.h"

class ContractBuilderTest : public testing::Test {
protected:
  ContractBuilderTest() {}
  ~ContractBuilderTest() override {}
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(ContractBuilderTest, SplittingFxPairStringToGetCurrencies) {
  std::string fx_ticker = "EUR/USD";
  std::optional<Contract> c_opt = ContractBuilder::CashFx(fx_ticker);
  ASSERT_TRUE(c_opt.has_value());
  Contract c = c_opt.value();
  EXPECT_EQ(c.symbol, "EUR");
  EXPECT_EQ(c.currency, "USD");

  fx_ticker = "USD/HKD";
  c_opt = ContractBuilder::CashFx(fx_ticker);
  ASSERT_TRUE(c_opt.has_value());
  c = c_opt.value();
  EXPECT_EQ(c.symbol, "USD");
  EXPECT_EQ(c.currency, "HKD");

}
