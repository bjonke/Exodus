//BitMapObject.h
#ifndef CBITMAPOBJECT_H
#define CBITMAPOBJECT_H
#pragma once
//we need this for windows stuff.
#include <windows.h>

class CBitMapObject
{
private:
	//memory dc
	HDC hdcMemory;
	//new bitmap!
	HBITMAP hbmNewBitMap;
	//old bitmap.
	HBITMAP hbmOldBitMap;
	//width & height as integers.
	int iWidth;
	int iHeight;
public:
	//constructor
	CBitMapObject();

	//destructor
	~CBitMapObject();

	//loads bitmap from a file
	void Load(HDC hdcCompatible,LPCTSTR lpszFilename);

	//creates a blank bitmap
	void Create(HDC hdcCompatible, int width, int height);

	//destroys bitmap and dc
	void Destroy();

	//return width
	int GetWidth();

	//return height
	int GetHeight();

	//converts to HDC
	operator HDC();
};

#endif
