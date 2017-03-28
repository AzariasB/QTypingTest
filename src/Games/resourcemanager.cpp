#include "resourcemanager.h"

ResourceManager::ResourceManager()
{

}

const QPixmap & ResourceManager::loadPixmap(const QString &key, const QString &fileName)
{
    if(!pixmaps_.contains(key)){
        QImage img(fileName);
        pixmaps_.insert(key, QPixmap::fromImage(img));
    }
	return pixmaps_[key];
}

const QPixmap & ResourceManager::getPixmap(const QString &key)
{
    //Cannot use pixmaps_[key] because lifetime of returned value is not long enougth
    //to live outside this function
    if(!pixmaps_.contains(key)){
        pixmaps_.insert(key, QPixmap());//Creating 'empty' pixmap to avoid game crashing
    }

    return pixmaps_.find(key).value();
}

