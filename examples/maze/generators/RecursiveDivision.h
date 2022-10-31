//
// Created by evan.norzow on 10/27/2022.
//

#ifndef MOBAGEN_RECURSIVEDIVISION_H
#define MOBAGEN_RECURSIVEDIVISION_H

#include "../MazeGeneratorBase.h"
#include "Point2D.h"
#include <map>
#include <vector>

struct Wall
{
  bool isHorizontal = false;
  int length = 0;
  Point2D startPos = Point2D(0, 0);
};

class RecursiveDivision : public MazeGeneratorBase
{
 private:
  std::vector<Wall*> stack;
  std::map<int, std::map<int, bool>> visited; // naive. not optimal
  Point2D randomStartPoint(World* world);
  std::vector<Point2D> getVisitables(World* w, const Point2D& p);
  void division(World* world, int x, int y, int width, int height, bool orientation);
  bool chooseOrientation(int width, int height);
 public:
  bool Step(World * world) override;
  void Clear(World * world) override;
};

#endif  // MOBAGEN_RECURSIVEDIVISION_H
