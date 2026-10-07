#include "plmn-encoding.h"

#include <stdexcept>

namespace ns3
{
namespace oran
{

namespace
{
int
Digit(const std::string& value, std::size_t index)
{
    if (value[index] < '0' || value[index] > '9')
    {
        throw std::invalid_argument("PLMN components must contain decimal digits");
    }
    return value[index] - '0';
}
} // namespace

void
EncodePlmnBcd(uint8_t output[3], const std::string& mcc, const std::string& mnc)
{
    if (mcc.size() != 3 || (mnc.size() != 2 && mnc.size() != 3))
    {
        throw std::invalid_argument("MCC must have 3 digits and MNC must have 2 or 3 digits");
    }
    const int mcc1 = Digit(mcc, 0);
    const int mcc2 = Digit(mcc, 1);
    const int mcc3 = Digit(mcc, 2);
    const int mnc1 = Digit(mnc, 0);
    const int mnc2 = Digit(mnc, 1);
    const int mnc3 = mnc.size() == 3 ? Digit(mnc, 2) : 0xF;
    output[0] = static_cast<uint8_t>((mcc2 << 4) | mcc1);
    output[1] = static_cast<uint8_t>((mnc3 << 4) | mcc3);
    output[2] = static_cast<uint8_t>((mnc2 << 4) | mnc1);
}

} // namespace oran
} // namespace ns3