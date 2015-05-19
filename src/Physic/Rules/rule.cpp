#include "rule.h"

using namespace std;

namespace sbg {

template<int n>
Rule<n>::~Rule(){}

template class Rule<2>;
template class Rule<3>;

}
