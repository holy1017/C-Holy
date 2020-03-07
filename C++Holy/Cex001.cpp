#include "Cex001.h"
class Cex001
{
	int i = 1;
public:
	int get_i() {
		return i;
	}
};
class Cex002
{
	int j = 2;
public:
	int get_j() {
		return j;
	}
};
class Cex003 : public Cex001, public Cex002 {
	int k = 3;
public:
	int get_k() {
		return k;
	}
};
