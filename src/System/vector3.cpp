#include "vector3.h"

#include "vector2.h"

using namespace std;

namespace sbg {

template struct Vector<3, float>;
template struct Vector<3, double>;
template struct Vector<3, long double>;
template struct Vector<3, int>;
template struct Vector<3, unsigned int>;
template struct Vector<3, long>;
template struct Vector<3, unsigned long>;
template struct Vector<3, short>;
template struct Vector<3, unsigned short>;
template struct Vector<3, char>;
template struct Vector<3, unsigned char>;

}
