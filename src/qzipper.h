#ifndef QZIPPER_H
#define QZIPPER_H

#include <QObject>
#include <iostream>
#include <QArchive.hpp>
#include <iostream>

#include "logger.h"

class QZipper : public QObject
{
    Q_OBJECT
public:
    explicit QZipper(QObject *parent = nullptr);
    ~QZipper();
signals:

public slots:
    void    slot_Compression(const QString& pathCompress, const QString& pathFolderToArchvie);
    void    slot_Decompression(const QString& pathFileExtract, const QString& pathFolderToExtract);
};

#endif // QZIPPER_H
