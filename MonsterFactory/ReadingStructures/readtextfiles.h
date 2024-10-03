#ifndef READTEXTFILES_H
#define READTEXTFILES_H

#include <QString>

class readTextFiles
{
public:
    readTextFiles();
    QString readTextFilesInFolder();
    void appendTextToFile(const QString& filePath, const QString& textToAdd);
};

#endif // READTEXTFILES_H
