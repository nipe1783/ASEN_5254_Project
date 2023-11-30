
#include <ompl/geometric/SimpleSetup.h>
#include <ompl/base/spaces/SE2StateSpace.h>
#include <ompl/geometric/planners/rrt/RRT.h>
#include <ompl/geometric/planners/sst/SST.h>
#include "World.h"
#include "StateValidityCheckerDatabase.h"
#include "PostProcessing.h"


namespace fs = std::filesystem;
namespace ob = ompl::base;
namespace og = ompl::geometric;

int main(int argc, char** argv) {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}