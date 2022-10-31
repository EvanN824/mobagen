//
// Created by evan.norzow on 10/27/2022.
//

#include "RecursiveDivision.h"
#include "../World.h"
#include "Random.h"

bool RecursiveDivision::Step(World* world)
{
    if (stack.empty())
    {

    } else
    {

    }
}

void RecursiveDivision::division(World* world, int x, int y, int width, int height, bool orientation)
{
  if (width < 2 || height < 2) {return;}
  
}

bool RecursiveDivision::chooseOrientation(int width, int height)
{
  //False is horizontal, True is vertical
  if (width < height) {return false;}
  else if(width > height) {return true;}

  return Random::Range(0,1);
}

void RecursiveDivision::Clear(World* world) {
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize()/2;

  for(int i=-sideOver2;i<=sideOver2;i++){
    for(int j=-sideOver2;j<=sideOver2;j++){
      visited[i][j] = false;
    }
  }
}

Point2D RecursiveDivision::randomStartPoint(World* world) {
  auto sideOver2 = world->GetSize()/2;

  for(int y=-sideOver2; y<=sideOver2; y++)
    for(int x=-sideOver2; x<=sideOver2; x++)
      if(!visited[y][x])
        return {x,y};
  return {INT_MAX, INT_MAX};
}