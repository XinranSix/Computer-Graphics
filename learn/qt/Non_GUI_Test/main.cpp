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

int main() {
  QRandomGenerator *rand1 =
      new QRandomGenerator(QDateTime::currentMSecsSinceEpoch());
  QRandomGenerator *rand2 =
      new QRandomGenerator(QDateTime::currentMSecsSinceEpoch());
  for (int i = 0; i < 5; ++i) {
    cout << rand1->generate() << ' ' << rand2->generate() << endl;
  }
  return 0;
}
