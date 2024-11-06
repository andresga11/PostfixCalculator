#include "BigInt.h"

#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace mesa;

BigInt::BigInt(std::string input)
{
  int i = 0;
  while ((i < input.length() - 1) && input[i] == '0')
  {
    i++;
  }
  for (; i < input.length(); ++i)
  {
    bigNum.push_back(input[i] - '0');
  }
}

BigInt::BigInt(const BigInt& other) : bigNum(other.bigNum){};

BigInt BigInt::operator+(const BigInt& other) const
{
  BigInt result(*this);
  result += other;
  return result;
}

BigInt& BigInt::operator+=(const BigInt& other)
{
  int carry = 0;
  BigInt tmp = other;
  std::vector<int> tmpSum;

  std::reverse(bigNum.begin(), bigNum.end());
  std::reverse(tmp.bigNum.begin(), tmp.bigNum.end());

  int i = 0;
  int j = 0;
  while (i < bigNum.size() || j < tmp.bigNum.size())
  {
    int sum = 0;
    if (i < bigNum.size() && j < tmp.bigNum.size())
    {
      sum += bigNum[i] + tmp.bigNum[j] + carry;
      i++;
      j++;
    }
    else if (i < bigNum.size())
    {
      sum += bigNum[i] + carry;
      i++;
    }
    else if (j < tmp.bigNum.size())
    {
      sum += tmp.bigNum[j] + carry;
      j++;
    }
    if (sum >= 10)
    {
      sum = sum - 10;
      carry = 1;
    }
    else
    {
      carry = 0;
    }
    tmpSum.push_back(sum);
  }
  if (carry > 0)
  {
    tmpSum.push_back(carry);
  }

  std::reverse(tmpSum.begin(), tmpSum.end());
  bigNum = tmpSum;
  return *this;
}

BigInt BigInt::operator*(const BigInt& other) const
{
  BigInt result(*this);
  result *= other;
  return result;
}

BigInt& BigInt::operator*=(const BigInt& other)
{
  if (bigNum.size() == 1 && bigNum[0] == 0)
  {
    bigNum.clear();
    bigNum.push_back(0);
    return *this;
  }
  if (other.bigNum.size() == 1 && other.bigNum[0] == 0)
  {
    bigNum.clear();
    bigNum.push_back(0);
    return *this;
  }

  std::vector<int> bigNum_res;
  std::vector<std::vector<int>> mat;
  for (auto other_dig_it = other.bigNum.crbegin(); other_dig_it != other.bigNum.crend(); ++other_dig_it)
  {
    mat.push_back(std::vector<int>());
    auto& vec = mat.back();
    const int other_dig = *other_dig_it;
    int carry = 0;

    for (auto dig_it = bigNum.crbegin(); dig_it != bigNum.crend(); ++dig_it)
    {
      const int dig = *dig_it;

      int prod = dig * other_dig;
      prod = (prod + carry) % 10;
      carry = (dig * other_dig + carry) / 10;

      vec.push_back(prod);
    }
    if (carry != 0)
    {
      vec.push_back(carry);
    }
  }

  bigNum_res = mat[0];
  for (int i = 1; i < mat.size(); ++i)
  {
    int carry = 0;
    auto& vec = mat[i];
    for (int j = 0; j < vec.size(); ++j)
    {
      if (bigNum_res.size() <= (j + i))
      {
        bigNum_res.push_back(0);
      }
      bigNum_res[j + i] = bigNum_res[j + i] + vec[j] + carry;
      carry = bigNum_res[j + i] / 10;
      bigNum_res[j + i] = bigNum_res[j + i] % 10;
    }
    if (carry != 0)
    {
      bigNum_res.push_back(carry);
    }
  }
  std::reverse(bigNum_res.begin(), bigNum_res.end());
  bigNum = bigNum_res;
  return *this;
}

BigInt BigInt::pow(const BigInt& exp)
{
  BigInt prod(*this);
  if (exp.bigNum.size() == 1 && exp.bigNum[0] == 0)
  {
    prod.bigNum.clear();
    prod.bigNum.push_back(1);
    return prod;
  }
  for (BigInt i = BigInt("1"); i < exp; i += BigInt("1"))
  {
    prod *= *this;
  }
  return prod;
}

bool BigInt::operator<(const BigInt& other) const
{
  if (bigNum.size() < other.bigNum.size())
  {
    return true;
  }
  else if (other.bigNum.size() < bigNum.size())
  {
    return false;
  }
  for (int i = 0; i < bigNum.size(); i++)
  {
    if (bigNum[i] != other.bigNum[i])
    {
      return bigNum[i] < other.bigNum[i];
    }
  }
  return false;
}

BigInt::operator std::string() const
{
  std::stringstream s;
  for (int i = 0; i < bigNum.size(); ++i)
  {
    s << bigNum[i];
  }
  return s.str();
}

std::ostream& mesa::operator<<(std::ostream& os, const BigInt& Bnum)
{
  os << std::string(Bnum);
  return os;
}

bool BigInt::operator==(const BigInt& other) const { return bigNum == other.bigNum; }