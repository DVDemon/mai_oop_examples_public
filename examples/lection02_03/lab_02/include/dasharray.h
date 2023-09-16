#pragma once

#include <string>
#include <iostream>

class DashArray
{ 
public:
   DashArray();
   DashArray(const size_t & n, unsigned char t = 0);
   DashArray(const std::initializer_list< unsigned char> &t);
   DashArray(const std::string &t);
   DashArray(const DashArray& other);
   DashArray(DashArray&& other) noexcept;      

   DashArray add(const DashArray& other);
   DashArray remove(const DashArray& other);
   bool      equals(const DashArray& other) const;
   std::ostream&   print(std::ostream& os);

   virtual ~DashArray() noexcept;
private:
    size_t _size;
    unsigned char *_array;
};
