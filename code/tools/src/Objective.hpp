#ifndef _OBJECTIVE_HPP_
#define _OBJECTIVE_HPP_

#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>

#include "ZeroObjectiveTerm.hpp"
#include "SingleObjectiveTerm.hpp"
#include "DoubleObjectiveTerm.hpp"
#include "TripleObjectiveTerm.hpp"

class Objective {
public:
    Objective();
    Objective(const Objective& obj);
    Objective&       operator=(const Objective& obj);
    void		     setMin(int min);
    void		     setMax(int max);
    void             setPrecision(int precision);
    int              getPrecision() const;
    int		         getMin() const;
    int 		     getMax() const;
    void             add(double d, std::vector<int> v);
    Objective        simplify(const std::vector<char>& v);
    void             add(ObjectiveTerm* o);
    int              size();
    std::vector<int> getFactors(int index);
    friend  std::ostream& operator<<(std::ostream& os, const Objective& obj);
    double 		     evaluate(const std::vector<bool>& values);
    Objective	     filter(std::set<int> variables);
    Objective	     filter(int minVar, int maxVar);
    Objective        setTo(int var, bool value);
    Objective        setToTrue(int var);
    Objective        setToFalse(int var);
    double           getIndependent() const;
    void             setIndependent(double d);
    // Change every variable to its translation
    // useful to go from variable indexes to positions
    // and vice versa
    void             translate(std::vector<int>& tr);
    void             addToIndependent(double d);
    ~Objective();
private:
    double independent = 0;
    std::vector<ObjectiveTerm*> fun;
    int min, max, precision;
    
};
#endif
