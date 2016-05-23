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

#ifndef ATOOLS_FS_SIMCONNECTREPLY_H
#define ATOOLS_FS_SIMCONNECTREPLY_H

#include "fs/sc/types.h"

#include <QString>

class QIODevice;

namespace atools {
namespace fs {
namespace sc {

class SimConnectReply
{
public:
  SimConnectReply();
  SimConnectReply(const SimConnectReply& other);
  ~SimConnectReply();

  bool read(QIODevice *ioDevice);
  int write(QIODevice *ioDevice);

  int getPacketId() const
  {
    return static_cast<int>(packetId);
  }

  void setPacketId(int value)
  {
    packetId = static_cast<quint32>(value);
  }

  int getPacketTs() const
  {
    return static_cast<int>(packetTs);
  }

  void setPacketTs(unsigned int value)
  {
    packetTs = static_cast<quint32>(value);
  }

  atools::fs::sc::SimConnectStatus getStatus() const
  {
    return status;
  }

  const QString& getStatusText() const
  {
    return SimConnectStatusText.at(status);
  }

private:
  const static quint16 MAGIC_NUMBER_REPLY = 0x55AA;
  const static quint16 REPLY_VERSION = 1;

  quint32 packetId = 0, packetTs = 0;
  atools::fs::sc::SimConnectStatus status = OK;
  quint16 magicNumber = 0, packetSize = 0, version = 1, padding;

};

} // namespace sc
} // namespace fs
} // namespace atools

Q_DECLARE_METATYPE(atools::fs::sc::SimConnectReply);

Q_DECLARE_TYPEINFO(atools::fs::sc::SimConnectReply, Q_PRIMITIVE_TYPE);

#endif // ATOOLS_FS_SIMCONNECTREPLY_H