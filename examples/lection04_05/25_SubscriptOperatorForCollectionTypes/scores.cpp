#include "scores.h"
#include <cassert>

double& Scores::operator[](size_t index){
    assert((index >= 0) &&(index < 20));
    std::cout << "reference" << std::endl;
    return m_scores[index];
 }

double Scores::operator[](size_t index) const{
    assert((index >= 0) &&(index < 20));
    std::cout << "const" << std::endl;
    return m_scores[index];
}