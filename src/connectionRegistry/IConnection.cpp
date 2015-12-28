/**
    @file   IConnection.cpp
    @author Lime Microsystems (www.limemicro.com)
    @brief  Implementation of IConnection interface
*/

#include "IConnection.h"
#include <cstring> //memcpy

DeviceInfo::DeviceInfo(void)
{
    return;
}

RFICInfo::RFICInfo(void):
    spiIndexRFIC(-1),
    spiIndexSi5351(-1),
    rxChannel(-1),
    txChannel(-1)
{
    return;
}

StreamMetadata::StreamMetadata(void):
    timestamp(-1),
    endOfBurst(false)
{
    return;
}

IConnection::IConnection(void)//:
    //m_connectionType(CONNECTION_UNDEFINED)
{
    callback_logData = nullptr;
    unsigned short test = 0x1234;
    unsigned char* bytes = (unsigned char*)&test;
    if(bytes[0] == 0x12 && bytes[1] == 0x34)
        mSystemBigEndian = true;
    else
        mSystemBigEndian = false;
}

IConnection::~IConnection(void)
{
    return;
}

bool IConnection::IsOpen(void)
{
    return false;
}

DeviceInfo IConnection::GetDeviceInfo(void)
{
    DeviceInfo info;
    return info;
}

std::vector<RFICInfo> IConnection::ListRFICs(void)
{
    return std::vector<RFICInfo>(1);
}

OperationStatus IConnection::DeviceReset(void)
{
    return UNSUPPORTED;
}

OperationStatus IConnection::TransactSPI(const int index, const uint32_t *writeData, uint32_t *readData, const size_t size)
{
    return UNSUPPORTED;
}

void IConnection::UpdateExternalBandSelect(const int trfBand, const int rfeBand)
{
    return;
}

double IConnection::GetReferenceClockRate(void)
{
    return 1.0;
}

void IConnection::SetReferenceClockRate(const double rate)
{
    return;
}

bool IConnection::RxStreamControl(const int streamID, const size_t burstSize, const StreamMetadata &metadata)
{
    return false;
}

int IConnection::ReadStream(const int streamID, void * const *buffs, const size_t length, const long timeout_ms, StreamMetadata &metadata)
{
    return -1;
}

int IConnection::WriteStream(const int streamID, const void * const *buffs, const size_t length, const long timeout_ms, const StreamMetadata &metadata)
{
    return -1;
}

/** @brief Sets callback function which gets called each time data is sent or received
*/
void IConnection::SetDataLogCallback(std::function<void(bool, const unsigned char*, const unsigned int)> callback)
{
    callback_logData = callback;
}

OperationStatus IConnection::ProgramWrite(const char *buffer, const size_t length, const int programmingMode, const int index)
{
    return UNSUPPORTED;
}

OperationStatus IConnection::ProgramRead(char *buffer, const size_t length, const int index)
{
    return UNSUPPORTED;
}

OperationStatus IConnection::GPIOWrite(const uint8_t *buffer, const size_t bufLength)
{
    return UNSUPPORTED;
}

OperationStatus IConnection::GPIORead(uint8_t *buffer, const size_t bufLength)
{
    return UNSUPPORTED;
}
