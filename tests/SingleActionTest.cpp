#include "TwsHistoricalDataClient.h"
#include <gtest/gtest.h>

class SingleActionTest : public testing::Test {
protected:
  SingleActionTest() {}
  ~SingleActionTest() override {}
  void SetUp() override {}
  void TearDown() override {}
};

// expected behavior is to connect to server, make request, parse request, then disconnect
TEST_F(SingleActionTest, DoSingleActionAndDisconnect) {
  TwsHistoricalDataClient client(ST_HISTORICALDATAREQUESTS);
}
