#include "CB.h"
CB* CB::getcb()
{
	static CB* cb;
	return cb;
}