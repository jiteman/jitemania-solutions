#include "cpp_standard/derived.h"
#include "cpp_standard/base.h"
#include "cpp_standard/internal.h"

#include <memory>
#include <iostream>


int main( int const /*argc*/, char const *const * /*argv*/ ) {
	{
		::std::cout << "Creation and destruction tests:" << ::std::endl;
		::std::cout << "----------------" << ::std::endl;
		auto example = ::std::make_unique< ::jsd::cpp_standard::Internal >();

		::std::cout << example->get_internal_info() << ::std::endl;

		::std::cout << "----------------" << ::std::endl;
		::std::cout << "Creation and destruction tests:" << ::std::endl;
	}

	{
		::std::cout << ::std::endl;
		::std::cout << "Copy and move tests (Internal):" << ::std::endl;
		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Internal internal_0;

		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Internal internal_1 = internal_0;
		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Internal internal_2 = std::move( internal_0 );

		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Internal internal_3;
		::std::cout << "----------------" << ::std::endl;
		internal_3 = internal_1;

		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Internal internal_4;
		::std::cout << "----------------" << ::std::endl;
		internal_4 = std::move( internal_2 );

		::std::cout << "----------------" << ::std::endl;
		::std::cout << "Copy and move tests (Internal): end" << ::std::endl;
	}

	{
		::std::cout << ::std::endl;
		::std::cout << "Copy and move tests (Base):" << ::std::endl;
		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Base base_0;

		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Base base_1 = base_0;
		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Base base_2 = std::move( base_0 );

		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Base base_3;
		::std::cout << "----------------" << ::std::endl;
		base_3 = base_1;

		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Base base_4;
		::std::cout << "----------------" << ::std::endl;
		base_4 = std::move( base_2 );

		::std::cout << "----------------" << ::std::endl;
		::std::cout << "Copy and move tests (Base): end" << ::std::endl;
	}

	{
		::std::cout << ::std::endl;
		::std::cout << "Copy and move tests (Derived):" << ::std::endl;
		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Derived derived_0;

		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Derived derived_1 = derived_0;
		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Derived derived_2 = std::move( derived_0 );

		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Derived derived_3;
		::std::cout << "----------------" << ::std::endl;
		derived_3 = derived_1;

		::std::cout << "----------------" << ::std::endl;
		::jsd::cpp_standard::Derived derived_4;
		::std::cout << "----------------" << ::std::endl;
		derived_4 = std::move( derived_2 );

		::std::cout << "----------------" << ::std::endl;
		::std::cout << "Copy and move tests (Derived): end" << ::std::endl;
	}


	return 0;
}
