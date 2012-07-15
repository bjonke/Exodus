#ifndef CRISKFONT_H
#define CRISKFONT_H

HFONT RiskFont;

class CRiskFont
{
private:

public:

	CRiskFont()
	{
	};

	void Initialize()
	{
		/*
		RiskFont = CreateFont(46, 28, 15, 0,
			FW_NORMAL, FALSE, FALSE, FALSE,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_ROMAN,
			"Times New Roman");
		*/

		SelectObject(BackBuffer, GetStockObject(DEFAULT_GUI_FONT));
		SetBkMode(BackBuffer, TRANSPARENT);
		SetTextColor(BackBuffer,RGB(0,255,0));
	}

	~CRiskFont() 
	{
		DeleteObject(gsFont);
	};
};
CRiskFont Text;
#endif