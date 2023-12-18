#pragma once

#include <functional>
#include "types/financial.hpp"


namespace fc
{
	template < typename T >
	using algorithm_i = std::function< computed_data_t< T > ( const opt_data_t<T>& optData, const T& s)>;

}
