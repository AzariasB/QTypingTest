#include "ttext.h"

TText::TText():
    title_(""),
    author_(""),
    text_("")
{

}

TText::TText(QDomElement textElem):
    title_(textElem.hasAttribute("title") ? textElem.attribute("title") : "" ),
    author_( textElem.hasAttribute("author") ? textElem.attribute("author") : "" ),
    text_(textElem.text().simplified())
{
}
