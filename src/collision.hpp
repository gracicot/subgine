#pragma once

#include "system.hpp"

#include "Collision/collisionbody.h"
#include "Collision/collisionentity.h"
#include "Collision/sat_able.h"
#include "Collision/point_able.h"
#include "Collision/aabb_able.h"
#include "Collision/aabbbox.h"
#include "Collision/line.h"
#include "Collision/circle.h"
#include "Collision/point.h"
#include "Collision/polygon.h"
#include "Collision/quadtree.h"
#include "Collision/compoundcollision.h"

#include "Collision/CollisionHandlers/collisionhandler.h"

#include "Collision/CollisionTester/collisiontester.h"
#include "Collision/CollisionTester/sattester.h"
#include "Collision/CollisionTester/quadtreetester.h"
#include "Collision/CollisionTester/compoundtester.h"

#include "Collision/CollisionResults/collisionresult.h"
#include "Collision/CollisionResults/resultdata.h"
#include "Collision/CollisionResults/satresult.h"
#include "Collision/satresultaccumulator.h"

#include "Collision/Engines/test.h"
#include "Collision/Engines/group.h"
#include "Collision/Engines/groupcontainer.h"
#include "Collision/Engines/collisionengine.h"
