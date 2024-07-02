#ifndef R2D2_DUMMY_CONTROL_HPP
#define R2D2_DUMMY_CONTROL_HPP

#include <Arduino.h>
#include "travel_control.hpp"

namespace asn {

class DummyControl {
public:
    DummyControl( TravelControl& travel_control );
    void main();

private:
    TravelControl& travel_control;
};

}  // namespace asn

#endif  // R2D2_DUMMY_CONTROL_HPP