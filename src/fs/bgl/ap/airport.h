/*****************************************************************************
* Copyright 2015-2016 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef ATOOLS_BGL_AIRPORT_H
#define ATOOLS_BGL_AIRPORT_H

#include "fs/bgl/record.h"
#include "fs/bgl/nav/waypoint.h"
#include "fs/bgl/ap/approach.h"
#include "fs/bgl/ap/apron.h"
#include "fs/bgl/ap/apron2.h"
#include "fs/bgl/ap/apronlight.h"
#include "fs/bgl/ap/parking.h"
#include "del/deleteairport.h"
#include "fs/bgl//bglposition.h"
#include "fs/bgl/ap/rw/runway.h"
#include "fs/bgl/ap/helipad.h"
#include "fs/bgl/ap/start.h"
#include "fs/bgl/ap/fence.h"
#include "fs/bgl/ap/taxipath.h"
#include "geo/rect.h"

#include <QList>
#include <QHash>

namespace atools {
namespace io {
class BinaryStream;
}
}

namespace atools {
namespace fs {
namespace bgl {
class Jetway;

namespace ap {

enum FuelAvailability
{
  NO_FUEL = 0,
  UNKNOWN_FUEL = 1,
  PRIOR_REQUEST = 2,
  YES = 3
};

enum FuelFlags
{
  OCTANE_73 = 0x00000003, // 0-1
  OCTANE_87 = 0x0000000c, // Bits 2-3
  OCTANE_100 = 0x00000030, // Bits 4-5
  OCTANE_130 = 0x000000c0, // Bits 6-7
  OCTANE_145 = 0x00000300, // Bits 8-9
  MOGAS = 0x00000c00, // Bits 10-11
  JET = 0x00003000, // Bits 12-13
  JETA = 0x0000c000, // Bits 14-15
  JETA1 = 0x00030000, // Bits 16-17
  JETAP = 0x000c0000, // Bits 18-19
  JETB = 0x00300000, // Bits 20-21
  JET4 = 0x00c00000, // Bits 22-23
  JET5 = 0x03000000, // Bits 24-22
  AVGAS = 0x40000000, // Bit 30
  JET_FUEL = 0x80000000 // Bit 31
};

} // namespace ap

class Airport :
  public atools::fs::bgl::Record
{
public:
  Airport(const atools::fs::BglReaderOptions *options, atools::io::BinaryStream *bs);
  virtual ~Airport();

  const QList<atools::fs::bgl::Approach>& getApproaches() const
  {
    return approaches;
  }

  const QList<atools::fs::bgl::Com>& getComs() const
  {
    return coms;
  }

  const QList<atools::fs::bgl::DeleteAirport>& getDeleteAirports() const
  {
    return deleteAirports;
  }

  unsigned int getFuelFlags() const
  {
    return fuelFlags;
  }

  const QString& getIdent() const
  {
    return ident;
  }

  float getMagVar() const
  {
    return magVar;
  }

  const QString& getName() const
  {
    return name;
  }

  const atools::fs::bgl::BglPosition& getPosition() const
  {
    return position;
  }

  const QString& getRegion() const
  {
    return region;
  }

  const QList<atools::fs::bgl::Runway>& getRunways() const
  {
    return runways;
  }

  bool hasTowerObj() const
  {
    return towerObj;
  }

  const atools::fs::bgl::BglPosition& getTowerPosition() const
  {
    return towerPosition;
  }

  const QList<atools::fs::bgl::Waypoint>& getWaypoints() const
  {
    return waypoints;
  }

  const QList<atools::fs::bgl::Parking>& getParkings() const
  {
    return parkings;
  }

  const QList<atools::fs::bgl::Helipad>& getHelipads() const
  {
    return helipads;
  }

  const QList<atools::fs::bgl::Start>& getStarts() const
  {
    return starts;
  }

  const QList<atools::fs::bgl::Apron>& getAprons() const
  {
    return aprons;
  }

  const QList<atools::fs::bgl::Apron2>& getAprons2() const
  {
    return aprons2;
  }

  const QList<atools::fs::bgl::ApronLight>& getApronsLights() const
  {
    return apronLights;
  }

  const QList<atools::fs::bgl::Fence>& getFences() const
  {
    return fences;
  }

  const QList<atools::fs::bgl::TaxiPath>& getTaxiPaths() const
  {
    return taxipaths;
  }

  bool isAirportClosed() const
  {
    return airportClosed;
  }

  const atools::geo::Rect& getBoundingRect() const
  {
    return boundingRect;
  }

  int getNumRunwayEndApproachLight() const
  {
    return numRunwayEndApproachLight;
  }

  int getNumRunwayEndIls() const
  {
    return numRunwayEndIls;
  }

  int getNumHardRunway() const
  {
    return numHardRunway;
  }

  int getNumRunwayEndClosed() const
  {
    return numRunwayEndClosed;
  }

  int getNumSoftRunway() const
  {
    return numSoftRunway;
  }

  int getNumWaterRunway() const
  {
    return numWaterRunway;
  }

  int getNumLightRunway() const
  {
    return numLightRunway;
  }

  int getNumRunwayEndVasi() const
  {
    return numRunwayEndVasi;
  }

  int getNumJetway() const
  {
    return numJetway;
  }

  int getNumBoundaryFence() const
  {
    return numBoundaryFence;
  }

  int getNumParkingGaRamp() const
  {
    return numParkingGaRamp;
  }

  int getNumParkingGate() const
  {
    return numParkingGate;
  }

  float getLongestRunwayLength() const
  {
    return longestRunwayLength;
  }

  float getLongestRunwayWidth() const
  {
    return longestRunwayWidth;
  }

  float getLongestRunwayHeading() const
  {
    return longestRunwayHeading;
  }

  atools::fs::bgl::rw::Surface getLongestRunwaySurface() const
  {
    return longestRunwaySurface;
  }

  atools::fs::bgl::ap::ParkingType getLargestParkingGaRamp() const
  {
    return largestParkingGaRamp;
  }

  atools::fs::bgl::ap::ParkingType getLargestParkingGate() const
  {
    return largestParkingGate;
  }

  bool isMilitary() const
  {
    return military;
  }

  int getNumParkingCargo() const
  {
    return numParkingCargo;
  }

  int getNumParkingMilitaryCargo() const
  {
    return numParkingMilitaryCargo;
  }

  int getNumParkingMilitaryCombat() const
  {
    return numParkingMilitaryCombat;
  }

  int getTowerFrequency() const
  {
    return towerFrequency;
  }

  int getAtisFrequency() const
  {
    return atisFrequency;
  }

  int getAwosFrequency() const
  {
    return awosFrequency;
  }

  int getAsosFrequency() const
  {
    return asosFrequency;
  }

  int getUnicomFrequency() const
  {
    return unicomFrequency;
  }

private:
  friend QDebug operator<<(QDebug out, const atools::fs::bgl::Airport& record);

  bool deleteRecord;
  atools::fs::bgl::BglPosition position, towerPosition;
  atools::geo::Rect boundingRect;
  float magVar;
  QString ident;
  QString region;

  unsigned int fuelFlags;
  QString name;
  bool towerObj = false, airportClosed = false, military = false;

  int numRunwayEndApproachLight = 0, numRunwayEndIls = 0, numHardRunway = 0,
      numRunwayEndClosed = 0, numSoftRunway = 0, numWaterRunway = 0, numLightRunway = 0,
      numRunwayEndVasi = 0, numJetway = 0, numBoundaryFence = 0,
      numParkingGaRamp = 0, numParkingGate = 0, numParkingCargo = 0, numParkingMilitaryCargo = 0,
      numParkingMilitaryCombat = 0;

  int towerFrequency = 0, atisFrequency = 0, awosFrequency = 0, asosFrequency = 0, unicomFrequency = 0;

  float longestRunwayLength = 0.f, longestRunwayWidth = 0.f, longestRunwayHeading = 0.f;

  atools::fs::bgl::rw::Surface longestRunwaySurface = atools::fs::bgl::rw::UNKNOWN;
  atools::fs::bgl::ap::ParkingType largestParkingGaRamp = atools::fs::bgl::ap::UNKNOWN_PARKING,
                                   largestParkingGate = atools::fs::bgl::ap::UNKNOWN_PARKING;

  QList<atools::fs::bgl::Runway> runways;
  QList<atools::fs::bgl::Parking> parkings;
  QList<atools::fs::bgl::Com> coms;
  QList<atools::fs::bgl::Helipad> helipads;
  QList<atools::fs::bgl::Start> starts;
  QList<atools::fs::bgl::Approach> approaches;
  QList<atools::fs::bgl::Waypoint> waypoints;
  QList<atools::fs::bgl::DeleteAirport> deleteAirports;
  QList<atools::fs::bgl::Apron> aprons;
  QList<atools::fs::bgl::Apron2> aprons2;
  QList<atools::fs::bgl::ApronLight> apronLights;
  QList<atools::fs::bgl::Fence> fences;
  QList<atools::fs::bgl::TaxiPath> taxipaths;

  void updateTaxiPaths(const QList<TaxiPoint>& taxipoints, const QStringList& taxinames);
  void updateParking(const QList<atools::fs::bgl::Jetway>& jetways, const QHash<int, int>& parkingNumberIndex);
  void updateSummaryFields();

  static const int MIN_RUNWAY_LENGTH = 10;
};

} // namespace bgl
} // namespace fs
} // namespace atools

#endif // ATOOLS_BGL_AIRPORT_H
