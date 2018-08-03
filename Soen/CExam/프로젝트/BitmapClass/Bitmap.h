class Bitmap
{
private:
	HBITMAP hBit;
	int width,height;
	void PrepareSize();

public:
	Bitmap() { hBit=NULL; }
	Bitmap(int ID) { Load(ID); }
	Bitmap(TCHAR *Path) { Load(Path); }
	Bitmap(int width,int height);
	~Bitmap() { UnLoad(); }
	bool Load(int ID);
	bool Load(TCHAR *Path);
	void UnLoad() { if (hBit) DeleteObject(hBit); }
	void Save(TCHAR *Path);
	void Draw(HDC hdc,int x,int y);
	void Draw(HDC hdc,int x,int y,int w,int h,int sx=0,int sy=0);
	void Draw(HDC hdc,int x,int y,COLORREF Mask);
	void Stretch(HDC hdc,int x,int y,int w,int h,int sx,int sy,
		int sw=-1,int sh=-1);
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	HBITMAP GetBitmap() { return hBit; }
};

