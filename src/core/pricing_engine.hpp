#pragma once

#include <optional>
#include <utility>

#include "algorithm_interface.hpp"
#include "types/financial.hpp"
#include "policies/checking.hpp"

namespace fc
{
	template <
		typename T,
		template < typename > class Input,
		template < typename > class Output,
		template < class > class CheckingPolicy = NoChecking
	> class PricingEngine: private Input< T >, private Output< T >
	{

	public:
		explicit PricingEngine(const algorithm_i<T>& conversion) : convert(conversion) {}
		void run(const T& t)
		{
			auto t1 = getData();
			CheckingPolicy< decltype( t1 ) >::Check(t1);
			computed_data_t<T> t2 = convert(t1, t);
			sendData(t2);
			end();
		}

	private:
		using Input<T>::getData;
		using Output<T>::sendData;
		using Output<T>::end;

		algorithm_i<T> convert;
	};

}

