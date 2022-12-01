#include <DxLib.h>
#include <cassert>
#include "DrawFunctions.h"

namespace my 
{
	int MyLoadGraph(const TCHAR* path)
	{
		int handle = LoadGraph(path);
		assert(handle >= 0);
		return handle;
	}
}// end of namespace my