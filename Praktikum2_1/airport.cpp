#include "airport.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
Airport::Airport(const QString& name, const QString& iso_country,
                 const QString& municipality, const QString& iata_code)
    : name_(name), iso_country_(iso_country), municipality_(municipality), iata_code_(iata_code) {}

QString Airport::name() const { return name_; }

void Airport::setName(const QString& name) { name_ = name; }

QString Airport::isoCountry() const { return iso_country_; }

void Airport::setIsoCountry(const QString& iso_country) { iso_country_ = iso_country; }

QString Airport::municipality() const { return municipality_; }

void Airport::setMunicipality(const QString& municipality) { municipality_ = municipality; }

QString Airport::iataCode() const { return iata_code_; }

void Airport::setIataCode(const QString& iata_code) { iata_code_ = iata_code; }

QMap<QString, Airport> readIataCodes() {
  QFile file("iatacodes.json");
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QMessageBox::critical(nullptr, "Fehler", "Konnte Datei nicht öffnen");
    return {};
  }

  QByteArray data = file.readAll();
  QJsonDocument doc = QJsonDocument::fromJson(data);
  if (doc.isNull()) {
    QMessageBox::critical(nullptr, "Fehler", "Konnte Datei nicht als JSON-Dokument einlesen");
    return {};
  }

  QJsonArray array = doc.array();
  QMap<QString, Airport> airports;
  for (const QJsonValue& value : array) {
    QJsonObject obj = value.toObject();
    Airport airport(obj["name"].toString(), obj["iso_country"].toString(),
                    obj["municipality"].toString(), obj["iata_code"].toString());
    airports.insert(airport.iataCode(), airport);
  }

  QMessageBox::information(nullptr, "Erfolg", "Datei erfolgreich eingelesen");
  return airports;
}
