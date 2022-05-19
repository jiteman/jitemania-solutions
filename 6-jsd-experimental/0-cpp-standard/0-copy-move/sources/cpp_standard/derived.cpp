#include "derived.h"

#include <iostream>


namespace jsd {
namespace cpp_standard {


// static
size_t Derived::_derived_counter = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::std::string Derived::get_derived_info() const noexcept {
	return "Originally " + _derived_original + " is " + _derived_string + " with ( " + this->get_base_info() + " )";
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Derived::~Derived() noexcept {
	::std::cout <<
		"Derived::~Derived() " <<
		( _derived_string.empty() ? ( "empty( originally was " + _derived_original + " )" ) : _derived_string ) <<
		::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Derived::Derived() noexcept
	:
		_derived_original( "Derived #" + ::std::to_string( ++_derived_counter ) ),
		_derived_string( _derived_original )
{
	::std::cout << "Derived::Derived() " << _derived_string << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Derived::Derived( Derived const &another ) noexcept
	:
		Base( another ),
		_derived_original( "Derived #" + ::std::to_string( ++_derived_counter ) ),
		_derived_string( _derived_original + " copy-constructed from " + another._derived_string )
{
	::std::cout << "Derived::Derived( Derived const &another ) " << _derived_string << ::std::endl;
}

Derived &Derived::operator =( Derived const &another ) noexcept {
	if ( &another == this ) return *this;

	Base::operator =( another );
	_derived_string = "Derived #" + ::std::to_string( ++_derived_counter ) + " copied from " + another._derived_string;
	::std::cout << "Derived::operator =( Derived const &another ) " << _derived_string << ::std::endl;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Derived::Derived( Derived &&another ) noexcept
	:
		Base( std::forward< Base >( another ) ),
		_derived_original( "Derived #" + ::std::to_string( ++_derived_counter ) ),
		_derived_string( std::move( another._derived_string ) )
{
	_derived_string = _derived_original + " move-constructed from " + _derived_string;
	::std::cout << "Derived::Derived( Derived &&another ) " << _derived_string << ::std::endl;
}

Derived &Derived::operator =( Derived &&another ) noexcept {
	if ( &another == this ) return *this;

	Base::operator =( std::forward< Base >( another ) );
	_derived_string = std::move( another._derived_string );
	_derived_string = "Derived #" + ::std::to_string( ++_derived_counter ) + " move-copied from " + _derived_string;
	::std::cout << "Derived::operator =( Derived &&another ) " << _derived_string << ::std::endl;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace cpp_standard
} // namespace jsd
