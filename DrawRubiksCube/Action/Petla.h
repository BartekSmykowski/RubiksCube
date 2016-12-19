

class Petla {
public:
	static void petlowanie(int i, void(*func)(int));
	static void petlowanie(int i, int j, void(*func)(int,int));
	static void petlowanie(int i, int j, int k, void(*func)(int,int,int));

};