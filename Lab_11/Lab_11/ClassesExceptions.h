#pragma once
#include <stdio.h>

class ex1 {
private:
	const char* message_;
	const char ch_;
public:
	explicit ex1(const char* message, const char ch) noexcept;
	const char* what() const noexcept;
	const char get_char() const noexcept;
};


class ex2{
private:
	const char* message_;
public:
	explicit ex2(const char* message) noexcept;
	const char* what() const noexcept;
};

