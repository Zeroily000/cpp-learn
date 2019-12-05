#include <boost/python.hpp>
#include <string>

std::string greet()
{
    return "Hello, World!";
}

BOOST_PYTHON_MODULE(myPyLib)
{
    using namespace boost::python;
    def("greet", greet);
}
