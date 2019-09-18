// by JJeong

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <exception>
#include "deque.hpp"
#include <string>

using namespace std;

struct coordinates {
	size_t width;
	size_t height;
};

TEST_CASE("Tests isEmpty()", "[deque]")
{
	Deque<int> b;
	REQUIRE(b.isEmpty());
	b.pushBack(100);
	b.pushFront(10000);
	REQUIRE(!(b.isEmpty()));
}

TEST_CASE("Tests front()", "[deque]")
{
	Deque<int> hi;
	Deque<float> bye;
	Deque<string> peace;
	REQUIRE_THROWS(hi.front());
	REQUIRE_THROWS(bye.front());
	REQUIRE_THROWS(peace.front());
	hi.pushFront(3);
	hi.pushFront(4);
	REQUIRE(hi.front() == 4);
	Deque<coordinates> abc;
	coordinates def;
	def.width = 0;
	def.height = 1;
	abc.pushFront(def);
	REQUIRE(abc.front().height == 1);
}

TEST_CASE("Tests back()", "[deque]")
{
	Deque<int> hi;
	Deque<float> bye;
	Deque<string> peace;
	REQUIRE_THROWS(hi.back());
	REQUIRE_THROWS(bye.back());
	REQUIRE_THROWS(peace.back());
	hi.pushBack(3);
	hi.pushBack(4);
	REQUIRE(hi.front() == 3);
}


TEST_CASE("Tests pushFront()", "[deque]")
{
	Deque<string> b;
	REQUIRE(b.isEmpty());
	b.pushFront("marryme");
	b.pushFront("hi");
	b.pushFront("bye");
	b.pushFront("2574");
	REQUIRE(b.front() == "2574");
}

TEST_CASE("Tests pushBack()", "[deque]")
{
	Deque<string> b;
	REQUIRE(b.isEmpty());
	b.pushBack("JYK");
	b.pushBack("Bye");
	b.pushBack("hiagain");
	REQUIRE(b.back() == "hiagain");
}

TEST_CASE("Tests popFront()", "[deque]")
{
	Deque<string> b;
	REQUIRE(b.isEmpty());
	b.pushFront("JYK");
	b.pushFront("marryme");
	b.pushFront("sayyes");
	b.pushBack("seoul");
	b.popFront();
	REQUIRE(b.front() == "marryme");
	Deque<int> sure;
	REQUIRE_THROWS(sure.popFront());
}

TEST_CASE("Tests popBack()", "[deque]")
{
	Deque<string> b;
	REQUIRE(b.isEmpty());
	b.pushFront("JYK");
	b.pushFront("marryme");
	b.pushFront("sayyes");
	b.pushFront("please");
	b.pushBack("dontsay");
	b.popBack();
	REQUIRE(b.back() == "JYK");
	Deque<int> sure;
	REQUIRE_THROWS(sure.popBack());
}

TEST_CASE("Tests copyConstructor", "[deque]")
{
	Deque<string> b;
	REQUIRE(b.isEmpty());
	b.pushFront("1");
	b.pushFront("2");
	b.pushFront("3");

	Deque<string> a = b;
	REQUIRE(a.front() == "3");
	REQUIRE(b.back() == "1");

	Deque<int> e;
	Deque<int> h = e;
	REQUIRE(h.isEmpty());
}

TEST_CASE("Tests copyAssignment operator", "[deque]")
{
	Deque<string> b;
	REQUIRE(b.isEmpty());
	b.pushFront("1");
	b.pushFront("2");
	b.pushFront("3");

	Deque<string> a;
	a.pushFront("4");
	a.pushFront("5");
	a.pushFront("6");

	a = b;
	REQUIRE(a.front() == "3");
	REQUIRE(b.back() == "1");

	Deque<int> c;
	REQUIRE(c.isEmpty());
	c.pushFront(1);
	c.pushFront(2);
	c.pushFront(3);

	Deque<int> d;
	d.pushFront(4);
	d.pushFront(5);
	d.pushFront(6);

	d = c;
	REQUIRE(c.front() == 3);
	REQUIRE(c.back() == 1);

	Deque<int> e;
	Deque<int> f;
	f = e;
	REQUIRE(f.isEmpty());
}

TEST_CASE("Tests return count", "[deque]")
{
	Deque<int> a;
	a.pushFront(1);
	a.pushFront(3);
	a.pushBack(100);
	REQUIRE(a.getLength() == 3);
}