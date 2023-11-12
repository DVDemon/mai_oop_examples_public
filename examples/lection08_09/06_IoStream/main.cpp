
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::istream_iterator
#include <vector>       // std::vector

int main() {
    double value1, value2;
    std::cout << "Please, insert two values: ";

    std::istream_iterator<double> eos; // end-of-stream iterator
    std::istream_iterator<double> iit(std::cin); // stdin iterator

    if (iit != eos) value1 = *iit;

    ++iit;
    if (iit != eos) value2 = *iit;

    std::cout << value1 << "*" << value2 << "=" << (value1 * value2) << '\n';

    
    std::cout << "Please, a lot of values: ";
    // insert iterator
    /*
    std::vector<double> vec;
    ++iit;
    std::insert_iterator<std::vector<double>> insert_it(vec,vec.begin());
    std::copy(iit,eos,insert_it);
    */
    ++iit;
    // 
    // while(iit!=eos){
    // vec.push_back(*iit);
    // ++iit;
    //}
    std::vector<double> vec(iit,eos);

    // ostream iterator
    std::ostream_iterator<double> out(std::cout," ");
    std::copy(vec.begin(),vec.end(),out);
    std::cout << std::endl;
    
    //for(auto v:vec) std::cout << " " << v;
    //std::cout << std::endl;
    
    return 0;
}