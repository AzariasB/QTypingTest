#include "ttext.h"

TText::TText():
	author_(""),
    title_(""),
    text_("")
{

}

TText::TText(const QDomElement &textElem):
	author_( textElem.hasAttribute("author") ? textElem.attribute("author") : "" ),
    title_(textElem.hasAttribute("title") ? textElem.attribute("title") : "" ),
    text_(textElem.text().simplified())
{
}
