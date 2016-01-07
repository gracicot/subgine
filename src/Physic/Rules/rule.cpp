#include "rule.h"

using namespace std;

namespace sbg {

template<int n>
Rule<n>::~Rule(){}

template struct Rule<2>;
template struct Rule<3>;

}
