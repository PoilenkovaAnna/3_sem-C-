
#include "ClassesExceptions.h"

ex1::ex1(const char* message, const char ch) noexcept
	: message_(message), ch_(ch) {}

const char* ex1::what() const noexcept {
	return message_;
}

const char ex1::get_char() const noexcept {
	return ch_;
}


ex2::ex2(const char* message) noexcept
	: message_(message) {}

const char* ex2::what() const noexcept {
	return message_;
}
