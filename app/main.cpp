#include "StdAfx.h"

#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <thread>

#include "TwsClient.h"

const unsigned MAX_ATTEMPTS = 50;
const unsigned SLEEP_TIME = 10;

/* IMPORTANT: always use your paper trading account. The code below will submit
 * orders as part of the demonstration. */
/* IB will not be responsible for accidental executions on your live account. */
/* Any stock or option symbols displayed are for illustrative purposes only and
 * are not intended to portray a recommendation. */
/* Before contacting our API support team please refer to the available
 * documentation. */
// int main(int argc, char **argv) {
//   // host arg 1
//   // port arg 2
//   // connectOptions arg 3
//   const char *host = argc > 1 ? argv[1] : "";
//   int port = argc > 2 ? atoi(argv[2]) : 0;
//   if (port <= 0)
//     port = 7497;
//   const char *connectOptions = argc > 3 ? argv[3] : "+PACEAPI";
//   int clientId = 0;
//
//   unsigned attempt = 0;
//   printf("Start of C++ Socket Client Test %u\n", attempt);
//
//   for (;;) {
//     ++attempt;
//     printf("Attempt %u of %u\n", attempt, MAX_ATTEMPTS);
//
//     TwsHistoricalDataClient client;
//
//     // Run time error will occur (here) if TestCppClient.exe is compiled in
//     // debug mode but TwsSocketClient.dll is compiled in Release mode
//     // TwsSocketClient.dll (in Release Mode) is copied by API installer into
//     // SysWOW64 folder within Windows directory
//
//     // PACEAPI "paces" messages so that messages sent > 50/s rate instead of a disconnection
//     if (connectOptions) {
//       client.setConnectOptions(connectOptions);
//     }
//
//     // host is 127.0.0.1 (localhost)
//     // port is 7497 (the default for paper trading - match this with the port listed in Global config inside TWS)
//     // TODO: what is clientID? by default 0, why?
//     client.connect(host, port, clientId);
//     // connect also starts the eReader thread
//
//     // TEST: is the ACK flag used to parse every tick?
//     while (client.isConnected()) {
//       client.processMessages();
//     }
//     if (attempt >= MAX_ATTEMPTS) {
//       break;
//     }
//
//     printf("Sleeping %u seconds before next attempt\n", SLEEP_TIME);
//     std::this_thread::sleep_for(std::chrono::seconds(SLEEP_TIME));
//   }
//
//   printf("End of C++ Socket Client Test\n");
// }

int main(int argc, char **argv) {
  TwsClient client(ST_HISTORICALDATAREQUESTS);
}
