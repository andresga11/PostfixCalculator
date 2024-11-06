#ifndef MESA_CISC187_BIGINT_H
#define MESA_CISC187_BIGINT_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace mesa
{
  class BigInt
  {
   private:
    std::vector<int> bigNum;

   public:
    BigInt(){};
    BigInt(std::string input);
    BigInt(const BigInt& other);


    BigInt pow(const BigInt& exp);
    operator std::string() const;
    BigInt operator+(const BigInt& other) const;
    BigInt& operator+=(const BigInt& other);
    BigInt operator*(const BigInt& other) const;
    BigInt& operator*=(const BigInt& other);
    bool operator<(const BigInt& other) const;
    bool operator==(const BigInt& other) const;
  };

  std::ostream& operator<<(std::ostream& os, const BigInt& num);

} 


#endif