#ifndef TTEXT_H
#define TTEXT_H

#include <QString>

/**
 * @brief The TText class
 * This class is used to have an interface for the text
 * the user can train on and have some informations about this
 * text
 */
class TText
{
public:
    TText();

    QString author()
    {
        return this->author_;
    }

    QString title()
    {
        return this->title_;
    }

    QString text()
    {
        return this->text_;
    }

    int difficulty()
    {
        return this->difficulty_;
    }

    TText* setAuthor(QString author)
    {
        this->author_ = author;
        return this;
    }

    TText* setTitle(QString title)
    {
        this->title_ = title;
        return this;
    }

    TText* setDifficulty(int difficulty)
    {
        this->difficulty_ = difficulty;
        return this;
    }

    TText *setText(QString text)
    {
        this->text_ = text;
        return this;
    }

private:
    /*The author of the text extract*/
    QString author_;

    /* The title of the text */
    QString title_;

    /* The text itself */
    QString text_;

    /* The difficulty of the text (todo : Azarias) */
    int difficulty_;
};

#endif // TTEXT_H
