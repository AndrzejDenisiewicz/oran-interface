/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#ifndef PLMN_ENCODING_H
#define PLMN_ENCODING_H

#include <cstdint>
#include <string>

namespace ns3
{
namespace oran
{

void EncodePlmnBcd(uint8_t output[3], const std::string& mcc, const std::string& mnc);

} // namespace oran
} // namespace ns3

#endif /* PLMN_ENCODING_H */