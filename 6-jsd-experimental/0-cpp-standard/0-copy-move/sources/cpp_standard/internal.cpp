#include "internal.h"

#include <utility>
#include <iostream>


namespace jsd {
namespace cpp_standard {


// static
size_t Internal::_internal_counter = 0;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::std::string Internal::get_internal_info() const noexcept {
	return "Originally " + _internal_original + " is " + _internal_string;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Internal::~Internal() noexcept {
	::std::cout <<
		"Internal::~Internal() " <<
		( _internal_string.empty() ? ( "empty( originally was " + _internal_original + " )" ) : _internal_string ) <<
		::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Internal::Internal() noexcept
	:
		_internal_original( "Internal #" + ::std::to_string( ++_internal_counter ) ),
		_internal_string( _internal_original )
{
	::std::cout << "Internal::Internal() " << _internal_string << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Internal::Internal( Internal const &another ) noexcept
	:
		_internal_original( "Internal #" + ::std::to_string( ++_internal_counter ) ),
		_internal_string( _internal_original + " copy-constructed from " + another._internal_string )
{
	::std::cout << "Internal::Internal( Internal const &another ) " << _internal_string << ::std::endl;
}

Internal &Internal::operator =( Internal const &another ) noexcept {
	if ( &another == this ) return *this;

	_internal_string = "Internal #" + ::std::to_string( ++_internal_counter ) + " copied from " + another._internal_string;
	::std::cout << "Internal::operator =( Internal const &another ) " << _internal_string << ::std::endl;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Internal::Internal( Internal &&another ) noexcept
	:
		_internal_original( "Internal #" + ::std::to_string( ++_internal_counter ) ),
		_internal_string( std::move( another._internal_string ) )
{
	_internal_string = _internal_original + " move-constructed from " + _internal_string;
	::std::cout << "Internal::Internal( Internal &&another ) " << _internal_string << ::std::endl;
}

Internal &Internal::operator =( Internal &&another ) noexcept {
	if ( &another == this ) return *this;

	_internal_string = std::move( another._internal_string );
	_internal_string = "Internal #" + ::std::to_string( ++_internal_counter ) + " move-copied from " + _internal_string;
	::std::cout << "Internal::operator =( Internal &&another ) " << _internal_string << ::std::endl;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace cpp_standard
} // namespace jsd
