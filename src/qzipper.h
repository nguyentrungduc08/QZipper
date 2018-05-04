#ifndef QZIPPER_H
#define QZIPPER_H

#include <QObject>
#include <iostream>
#include "QArchive.hpp"

class QZipper : public QObject
{
    Q_OBJECT
public:
    explicit QZipper(QObject *parent = nullptr);
    ~QZipper();
signals:

public slots:
};

#endif // QZIPPER_H
