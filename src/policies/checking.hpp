#pragma once


#include <exception>
#include <optional>

namespace fc
{
	template < class T > struct NoChecking
	{
		static void Check(T*) {}
		static void Check(std::optional<T>& opt) {}
	};

	template < class T > struct EnforceNotNull
	{
		struct NullPointerException : public std::exception
		{
			const char* what() const noexcept override
			{
				return "Null pointer exception";
			}
		};
		static void Check(T* ptr)
		{
			if (!ptr) throw NullPointerException();
		}

		static void Check(std::optional<T>& opt)
		{
			if (!opt.has_value()) throw NullPointerException();
		}
	};
}