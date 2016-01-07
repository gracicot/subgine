#include "vector4.h"

#include <ostream>
#include <cmath>

using namespace std;

namespace sbg {

template struct Vector<4, float>;
template struct Vector<4, double>;
template struct Vector<4, long double>;
template struct Vector<4, int>;
template struct Vector<4, unsigned int>;
template struct Vector<4, long>;
template struct Vector<4, unsigned long>;
template struct Vector<4, short>;
template struct Vector<4, unsigned short>;
template struct Vector<4, char>;
template struct Vector<4, unsigned char>;

}
