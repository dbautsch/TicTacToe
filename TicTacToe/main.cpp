#include "main.hpp"

#ifdef _WINDOWS_

int APIENTRY WinMain
(
	HINSTANCE hThisInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd
)
#else
int main
(
	int argc,
	char * argv []
)
#endif

{
	Game g;

	return g.Run();
}
