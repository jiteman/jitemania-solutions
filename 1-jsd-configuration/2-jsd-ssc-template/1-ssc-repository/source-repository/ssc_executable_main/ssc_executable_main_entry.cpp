#include "Ssc_executable_class.h"

#include "ssc_executable_function.h"
#include "ssc_derived_function.h"
#include "ssc_base_function.h"


#include <iostream>


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	auto *example = new ::jsd::ssc_executable::Ssc_executable_class;

	::std::cout << example->say_base_hello() << ::std::endl;
	::std::cout << example->say_derived_hello() << ::std::endl;
	::std::cout << example->say_executable_hello() << ::std::endl;

	::std::cout << jsd_ssc_base_function_say_executable_hello() << ::std::endl;
	::std::cout << jsd_ssc_derived_function_say_executable_hello() << ::std::endl;
	::std::cout << jsd_ssc_executable_function_say_executable_hello() << ::std::endl;

	delete example;

	return 0;
}
