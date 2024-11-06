#include <time.h>
#include <exception>
#include <iostream>

#include "WSG50Controller.h"

// #include <boost/thread/thread.hpp>

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif

#ifndef RAD
#define RAD(A) ((A) * PI / 180.0)
#endif

#ifndef DEG
#define DEG(A) ((A) * 180.0 / PI)
#endif

int main(int argc, char* argv[]) {
  // create controller
  //
  WSG50Controller wsgController("192.168.1.101", "1000");

  while (!wsgController.ready()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  // homing
  wsgController.homing(80.0);

  while (!wsgController.ready()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  // move to position
  wsgController.prePositionFingers(true, 20.0, 100.0);

  while (!wsgController.ready()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  std::cout << "Done." << std::endl;
  return 0;
}