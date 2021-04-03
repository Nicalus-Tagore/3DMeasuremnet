#ifndef ERROHANDLE_H
#define ERROHANDLE_H

#include <QWidget>
#include <NIMCExample.h>
class ErroHandle : public QWidget
{
    Q_OBJECT
public:
    explicit ErroHandle(QWidget *parent = nullptr);
    void nimcDisplayError(i32 errorCode, u16 commandID, u16 resourceID);

signals:

};

#endif // ERROHANDLE_H
