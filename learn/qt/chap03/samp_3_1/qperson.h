#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author", "J. Yao")
    Q_CLASSINFO("company", "WIT")
    Q_CLASSINFO("version","1.0.0")
    Q_PROPERTY(unsigned age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)
private:
    unsigned m_age = 10;
    QString m_name;
    int m_score = 79;
public:
    explicit QPerson(QString name,QObject *parent = nullptr);
    unsigned age();
    void setAge(unsigned value);
    void incAge();

signals:
    void ageChanged(unsigned value);
};

#endif // QPERSON_H
