#include "base.h"

#include <iostream>


namespace jsd {
namespace cpp_standard {


// static
size_t Base::_base_counter = 0;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::std::string Base::get_base_info() const noexcept {
	return "Originally " + _base_original + " is " + _base_string + " with ( " + _the_internal.get_internal_info() + " )";
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Base::~Base() noexcept {
	::std::cout <<
		"Base::~Base() " <<
		( _base_string.empty() ? ( "empty( originally was " + _base_original + " )" ) : _base_string ) <<
		::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Base::Base() noexcept
	:
		_base_original( "Base #" + ::std::to_string( ++_base_counter ) ),
		_base_string( _base_original ),
		_the_internal( Internal() )
{
	::std::cout << "Base::Base() " << _base_string << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Base::Base( Base const &another ) noexcept
	:
		_base_original( "Base #" + ::std::to_string( ++_base_counter ) ),
		_base_string( _base_original + " copy-constructed from " + another._base_string ),
		_the_internal( another._the_internal )
{
	::std::cout << "Base::Base( Base const &another ) " << _base_string << ::std::endl;
}

Base &Base::operator =( Base const &another ) noexcept {
	if ( &another == this ) return *this;

	_base_string = "Base #" + ::std::to_string( ++_base_counter ) + " copied from " + another._base_string;
	_the_internal = another._the_internal;
	::std::cout << "Base::operator =( Base const &another ) " << _base_string << ::std::endl;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Base::Base( Base &&another ) noexcept
	:
		_base_original( "Base #" + ::std::to_string( ++_base_counter ) ),
		_base_string( std::move( another._base_string ) ),
		_the_internal( ::std::move( another._the_internal ) )
{
	_base_string = _base_original + " move-constructed from " + _base_string;
	::std::cout << "Base::Base( Base &&another ) " << _base_string << ::std::endl;
}

Base &Base::operator =( Base &&another ) noexcept {
	if ( &another == this ) return *this;

	_base_string = std::move( another._base_string );
	_base_string = "Base #" + ::std::to_string( ++_base_counter ) + " move-copied from " + _base_string;
	_the_internal = ::std::move( another._the_internal );
	::std::cout << "Base::operator =( Base &&another ) " << _base_string << ::std::endl;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace cpp_standard
} // namespace jsd
