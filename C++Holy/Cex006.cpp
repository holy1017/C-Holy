class C006
{
public:
	
	int lenW, lenH;
	int minX, minY, maxX, maxY;
	bool** arr;
	
	C006();
	C006(int lenW ,int minY);
	
	
	~C006();


private:

};

C006::C006(int lenW, int minY)
{
	int** ary = new int* [lenW];
	for (int i = 0; i < minY; ++i) {
		ary[i] = new int[minY];
	}

}

C006::C006()
{

}

C006::~C006()
{

}