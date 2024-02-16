#include "pch.h"
#include "UIStart.h"
#include "TextGo.h"

UIStart::UIStart(const std::string& name) : TextGo(name)
{
}

void UIStart::Reset()
{
	text.setString(textFormat);
	SetOrigin(Origins::MC);
}
