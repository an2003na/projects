#include "string.h"

int main() {
	String s;
	std::cout << s.length() << std::endl;
	s.push_back('f');
	s.push_back('r');
	s.push_back('a');
	s.push_back('n');
	s.push_back('k');
	s.push_back('f');
	s.push_back('u');
	s.push_back('r');
	s.push_back('t');
	s.push_back('k');
	s.push_back('r');
	s.push_back('a');
	s.push_back('b');
	s.push_back('s');
	s.push_back('b');
	s.push_back('u');
	s.push_back('r');
	s.push_back('g');
	s.push_back('e');
	s.push_back('r');
	std::cout << s.length() << std::endl;

	String s1;
	s1.push_back('k');

	s.print();
	String s2(s);
//
	String s3("sgfkiogjd");
	s3.print();
	s+s1;
	s.print();
	std::cout << s3.length();
	return 0;
}
