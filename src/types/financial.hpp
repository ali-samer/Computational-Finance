#pragma once


#include <tuple>

namespace fc
{
// Option data {K, T, r, sig/v} from Input system
	template < typename T >
	using opt_data_t = std::tuple< T , T , T , T >;

// Return type of Algorithm system
// We compute V, delta and gamma
	template < typename T >
	using computed_data_t = std::tuple < T , T , T >;

}

