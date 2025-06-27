//
// Created by xqula on 27.06.24.
//

#include "core.h"
#include "transport/transportbase.h"
#include "transport/bus.h"
#include "transport/passengercar.h"
#include "transport/plane.h"
#include "transport/train.h"
#include "transport/watervehicles.h"
#include "memory"

auto Core::process() -> void {
    const auto transport = std::make_unique<Bus>("Bus", "BMW", 30);
    transport->out();
    const auto transport2 = std::make_unique<PassengerCar>("PassengerCar", "Audi", 5);
    transport2->out();
    const auto transport3 = std::make_unique<Plane>("Plane", "Airbus", 45);
    transport3->out();
    const auto transport4 = std::make_unique<Train>("Train", "RZHD", 185);
    transport4->out();
    const auto transport5 = std::make_unique<WaterVehicles>("WaterVehicles", "Ferrari", 15);
    transport5->out();
}
