/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   resourcemanager.h
 * Author: azarias
 *
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QImage>
#include <QPixmap>
#include <QHash>

class ResourceManager
{
public:
	ResourceManager();

        /**
         * @brief loadPixmap
         * Reads the image with the given filename into the memory
         * @param key the key of the pixmap to saved (used latter to retreive the data)
         * @param fileName the name of the file to load in memory
         * @return
         */
        const QPixmap &loadPixmap(const QString &key, const QString &fileName);

        /**
         * @brief getPixmap
         * Returns the pixmap with the given key
         * @param key the key of the file used when loading it
         * @return the pixmap found
         */
        const QPixmap &getPixmap(const QString &key);

private:

        /**
         * @brief pixmaps_
         * List of all the pixmaps
         */
        QHash<QString, QPixmap> pixmaps_;
};

#endif // RESOURCEMANAGER_H
