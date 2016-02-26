#ifndef AVAILABLELANGS
#define AVAILABLELANGS

const QStringList availableLanguages = {
    QLocale(QLocale::French,QLocale::France).nativeLanguageName(),
    QLocale(QLocale::English).nativeLanguageName(),
    QLocale(QLocale::Swedish,QLocale::Sweden).nativeLanguageName()
};

#endif // AVAILABLELANGS

