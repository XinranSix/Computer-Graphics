#include <QDateTime>
#include <QHash>
#include <QList>
#include <QMap>
#include <QMultiHash>
#include <QMultiMap>
#include <QQueue>
#include <QRandomGenerator>
#include <QSet>
#include <QStack>
#include <QString>
#include <QVector>
#include <QtGlobal>
#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, QString str) {
  return os << str.toStdString();
}

int main() {
  QString str1 = "Hello ";
  QString str2 = "World";
  QString str3 = str1 + str2;
  cout << str1 << endl << str2 << endl << str3 << endl;

  return 0;
}
