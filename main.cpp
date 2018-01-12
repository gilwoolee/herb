#include <dart/common/Console.hpp>
#include <dart/common/StlHelpers.hpp>
#include <dart/common/Timer.hpp>
#include <dart/utils/urdf/DartLoader.hpp>
#include <dart/dart.hpp>
#include <dart/gui/gui.hpp>
// #include <srdfdom/model.h>
// #include <urusing namespace dart::common;
using namespace dart::dynamics;
using namespace dart::simulation;
using namespace dart::math;
int main(int argc, char* argv[])
{
  dart::utils::DartLoader loader;

  std::string path = "/home/gilwoo/School_Workspace/magi_ws/devel/.private/herb_description/share/herb_description/robots/herb.urdf";

  loader.addPackageDirectory ("herb_description",
    "/home/gilwoo/School_Workspace/aikido_ws/src/herb_description");

  auto herb = loader.parseSkeleton(path);

  WorldPtr world = std::make_shared<World>();
  world->addSkeleton(herb);

  dart::gui::SimWindow window;
  window.setWorld(world);

  glutInit(&argc, argv);
  window.initWindow(640, 480, "Dominoes");
  glutMainLoop();
}