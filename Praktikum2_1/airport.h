#ifndef AIRPORT_H
#define AIRPORT_H

#include <QString>

class Airport {
 public:
  Airport(const QString& name = "", const QString& iso_country = "",
          const QString& municipality = "", const QString& iata_code = "");

  QString name() const;
  void setName(const QString& name);
  QString isoCountry() const;
  void setIsoCountry(const QString& iso_country);
  QString municipality() const;
  void setMunicipality(const QString& municipality);
  QString iataCode() const;
  void setIataCode(const QString& iata_code);
  QMap<QString, Airport> readIataCodes();
 private:
  QString name_;
  QString iso_country_;
  QString municipality_;
  QString iata_code_;
};

#endif // AIRPORT_H
